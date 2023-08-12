#include <stdio.h>

int main() {
    int i, j;
    int b[5][5];
    int a[5][5];
    int c[5][5];
    int choice;

    while (1) {
        printf("Enter values for matrix A:\n");
        for (i = 0; i < 2; i++) {
            for (j = 0; j < 2; j++) {
                printf("Enter a number: ");
                scanf("%d", &a[i][j]);
            }
        }

        printf("Matrix A:\n");
        for (i = 0; i < 2; i++) {
            for (j = 0; j < 2; j++) {
                printf("%d    ", a[i][j]);
            }
            printf("\n");
        }

        printf("Enter values for matrix B:\n");
        for (i = 0; i < 2; i++) {
            for (j = 0; j < 2; j++) {
                printf("Enter a number: ");
                scanf("%d", &b[i][j]);
            }
        }

        printf("Matrix B:\n");
        for (i = 0; i < 2; i++) {
            for (j = 0; j < 2; j++) {
                printf("%d    ", b[i][j]);
            }
            printf("\n");
        }

        printf("\nPress 1 for Addition\nPress 2 for Subtraction\nPress 3 for Multiplication\nPress 4 for Division\nPress 5 to Exit\n");
        scanf("%d", &choice);

        if (choice == 5) {
            printf("Exiting the program.\n");
            break; // Exit the loop
        }

        switch (choice) {
            case 1:
                printf("Matrix C (Addition):\n");
                for (i = 0; i < 2; i++) {
                    for (j = 0; j < 2; j++) {
                        c[i][j] = a[i][j] + b[i][j];
                        printf("%d  ", c[i][j]);
                    }
                    printf("\n");
                }
                break;

            case 2:
                printf("Matrix C (Subtraction):\n");
                for (i = 0; i < 2; i++) {
                    for (j = 0; j < 2; j++) {
                        c[i][j] = a[i][j] - b[i][j];
                        printf("%d  ", c[i][j]);
                    }
                    printf("\n");
                }
                break;

            case 3:
                printf("Matrix C (Multiplication):\n");
                for (i = 0; i < 2; i++) {
                    for (j = 0; j < 2; j++) {
                        c[i][j] = a[i][j] * b[i][j];
                        printf("%d  ", c[i][j]);
                    }
                    printf("\n");
                }
                break;

            case 4:
                printf("Matrix C (Division):\n");
                for (i = 0; i < 2; i++) {
                    for (j = 0; j < 2; j++) {
                        if (b[i][j] != 0) {
                            c[i][j] = a[i][j] / b[i][j];
                            printf("%d  ", c[i][j]);
                        } else {
                            printf("Undefined  ");
                        }
                    }
                    printf("\n");
                }
                break;

            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}
