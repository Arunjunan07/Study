#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int sock = 0;
    struct sockaddr_in ser;
    char buffer[1024] = {0};

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }
    ser.sin_family = AF_INET;
    ser.sin_port = htons(8080);

    // Convert IP address from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &ser.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        close(sock);
    }

    if (connect(sock, (struct sockaddr *)&ser, sizeof(ser)) < 0) {
        printf("Connection Failed \n");
        close(sock);
    }

    printf("Connected to the server!\n");

    while (1) {
        printf("You: ");
        scanf("%[^\n]%*c", buffer);
        
        if (strcmp(buffer, "exit") == 0) {
            printf("Exiting chat...\n");
            break;
        }

        send(sock, buffer, strlen(buffer), 0);

        int val = read(sock, buffer, 1024);
        if (val > 0) {
            buffer[val] = '\0';
            printf("Server: %s\n", buffer);
        }
    }
    close(sock);

    return 0;
}