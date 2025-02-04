#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>

int main()
{
	int sockfd, len, result, count;
	struct sockaddr_in address;
	char str[300], instr[300];
	int client_said_bye = 0, server_said_bye = 0;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = inet_addr("127.0.0.1");
	address.sin_port = 9129;
	len = sizeof(address);

	result = connect(sockfd, (struct sockaddr*)&address, len);
	if (result == -1) {
		printf("Connection error\n");
		exit(1);
	}

	while (1) {
		if (!client_said_bye) {
			fflush(stdout);
			printf("Enter Client-Side string: ");
			fgets(instr, 80, stdin);
			instr[strcspn(instr, "\n")] = 0; // Remove trailing newline

			if (strcmp(instr, "bye") == 0 || strcmp(instr, "Bye") == 0) {
				client_said_bye = 1;
			}

			write(sockfd, instr, strlen(instr) + 1);
		}

		count = read(sockfd, str, 300);
		str[count] = '\0';
		printf("\nReceived data from server: %s\n", str);

		if (strcmp(str, "bye") == 0 || strcmp(str, "Bye") == 0) {
			server_said_bye = 1;
		}

		if (client_said_bye && server_said_bye) {
			printf("Both sides said bye. Ending conversation.\n");
			break;
		}
	}

	close(sockfd);
	return 0;
}

