#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int sfd;
    struct sockaddr_in ser, cli;
    socklen_t len = sizeof(cli);
    char buffer[1024] = {0};

    if ((sfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(0);
    }

    memset(&ser, 0, sizeof(ser));
    ser.sin_family = AF_INET;
    ser.sin_addr.s_addr = INADDR_ANY;
    ser.sin_port = htons(8080);

    if (bind(sfd, (const struct sockaddr *)&ser, sizeof(ser)) < 0) {
        perror("Bind failed");
        close(sfd);
    }

    printf("Server is listening on port %d...\n", 8080);

    while (1) {
        int n = recvfrom(sfd, buffer, 1024, 0, (struct sockaddr *)&cli, &len);
        if (n < 0) {
            perror("Receive failed");
            continue;
        }
        buffer[n] = '\0';
        printf("Client: %s\n", buffer);

        printf("Server: ");
        scanf("%[^\n]%*c", buffer);  
        sendto(sfd, buffer, strlen(buffer), 0, (struct sockaddr *)&cli, len);
    }
    
    close(sfd);
    return 0;
}