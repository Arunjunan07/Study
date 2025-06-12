#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int sock = 0;
    struct sockaddr_in ser;
    char buffer[1024] = {0};

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        printf("\n Socket creation error \n");

    ser.sin_family = AF_INET;
    ser.sin_port = htons(8080);

    if (inet_pton(AF_INET, "127.0.0.1", &ser.sin_addr) <= 0)
        printf("\nInvalid address/ Address not supported \n");

    if (connect(sock, (struct sockaddr *)&ser, sizeof(ser)) < 0){
        printf("Connection Failed \n");
        exit(0);
    }

    printf("Enter message to send to the server: ");
    fgets(buffer, sizeof(buffer), stdin);  

    send(sock, buffer, strlen(buffer), 0);

    int val = read(sock, buffer, 1024);
    if (val < 0) {
        printf("Read failed\n");
        close(sock);
    }

    printf("Server response: %s\n", buffer);

    close(sock);
    return 0;
}

