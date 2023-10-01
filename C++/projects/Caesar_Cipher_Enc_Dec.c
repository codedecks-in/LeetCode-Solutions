// Using Switch-case in C program to illustrate menu-Driven program
// Made by Bishal Aryal | Twitter @C15C01337

#include <stdio.h>
#include <stdlib.h>

int input();
void output(float);
int main() {
    float result;
    int choice, num;
    printf("Choose 1 to encryption of caesar cipher\n");
    printf("Press 2 to decryption of caesar cipher\n");
    printf("Press 3 to exit\n");
    printf("Enter your choice:\n");
    choice = input();

    switch (choice) {
    case 1: {

        int main() {
            char message[100], ch;
            int i, key;
            printf("Enter a message to encrypt: ");
            scanf("%s", & message);

            printf("Enter key: ");
            scanf("%d", & key);
            for (i = 0; message[i] != '\0'; ++i) {
                ch = message[i];
                if (ch >= 'a' && ch <= 'z') {
                    ch = ch + key;
                    if (ch > 'z') {
                        ch = ch - 'z' + 'a' - 1;
                    }
                    message[i] = ch;
                } else if (ch >= 'A' && ch <= 'Z') {
                    ch = ch + key;
                    if (ch > 'Z') {
                        ch = ch - 'Z' + 'A' - 1;
                    }
                    message[i] = ch;
                }
            }
            printf("Encrypted message: %s", message);
            return 0;
        }
        main();
    }
    case 2: {

        int main() {
            char message[100], ch;
            int i, key;
            printf("Enter a message to decrypt: ");
            scanf("%s", & message);
            printf("Enter key: ");
            scanf("%d", & key);
            for (i = 0; message[i] != '\0'; ++i) {
                ch = message[i];
                if (ch >= 'a' && ch <= 'z') {
                    ch = ch - key;
                    if (ch < 'a') {
                        ch = ch + 'z' - 'a' + 1;
                    }
                    message[i] = ch;
                } else if (ch >= 'A' && ch <= 'Z') {
                    ch = ch - key;
                    if (ch < 'A') {
                        ch = ch + 'Z' - 'A' + 1;
                    }
                    message[i] = ch;
                }
            }
            printf("Decrypted message: %s", message);
            return 0;
        }
        main();
    }

    case 3: {
        printf("Thank you for using it:)");
        exit(0);

    }
    default:
        printf("wrong Input\n");
    }
    return 0;
}
int input() {
    int number;
    scanf("%d", & number);
    return (number);
}

void output(float number) {
    printf("%f", number);
}
