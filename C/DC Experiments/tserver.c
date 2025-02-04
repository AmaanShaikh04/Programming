#include<sys/types.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<stdio.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>
#include<pthread.h>

void *server_thread(void *arg)
{
	int client_sockfd = (int)arg;
	char instr[300], response[300];
	int client_said_bye = 0, server_said_bye = 0;

	while (1) {
		int count = read(client_sockfd, instr, 300);
		instr[count] = '\0';

		if (strcmp(instr, "bye") == 0 || strcmp(instr, "Bye") == 0) {
			client_said_bye = 1;
		} else {
			printf("Input from Client: %s\n", instr);
		}

		if (!server_said_bye) {
			printf("Enter Server-Side string: ");
			fgets(response, 300, stdin);
			response[strcspn(response, "\n")] = 0; // Remove trailing newline

			if (strcmp(response, "bye") == 0 || strcmp(response, "Bye") == 0) {
				server_said_bye = 1;
			}

			write(client_sockfd, response, strlen(response) + 1);
		}

		if (client_said_bye && server_said_bye) {
			printf("Both sides said bye. Ending conversation.\n");
			break;
		}
	}

	close(client_sockfd);
	pthread_exit(NULL);
}

int main()
{
	int server_sockfd, client_sockfd;
	int server_len, client_len;
	struct sockaddr_in server_address, client_address;
	pthread_t t;

	server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
	server_address.sin_port = 9129;
	server_len = sizeof(server_address);

	if (bind(server_sockfd, (struct sockaddr*)&server_address, server_len) == -1) {
		printf("Server error\n");
		exit(1);
	}

	printf("Server waiting....\n");
	listen(server_sockfd, 5);

	while (1) {
		client_len = sizeof(client_address);
		client_sockfd = accept(server_sockfd, (struct sockaddr*)&client_address, &client_len);
		printf("Created new client thread %d\n", client_sockfd);
		pthread_create(&t, NULL, server_thread, (void *)client_sockfd);
	}

	return 0;
}

