#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int sfd;
    struct sockaddr_in ser;
    char buffer[1024] = {0};
    
    // Create a UDP socket
    if ((sfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(0);
    }
    // Set up the server address
    memset(&ser, 0, sizeof(ser));
    ser.sin_family = AF_INET;
    ser.sin_port = htons(8080);
    ser.sin_addr.s_addr = inet_addr("127.0.0.1");  // Localhost

    printf("Connected to server at 127.0.0.1:%d\n", 8080);

    while (1) {
        printf("You: ");
        scanf("%[^\n]%*c", buffer);
        
        if (strcmp(buffer, "exit") == 0) {
            printf("Exiting chat...\n");
            break;
        }
        sendto(sfd, buffer, strlen(buffer), 0, (struct sockaddr *)&ser, sizeof(ser));

        int n = recvfrom(sfd, buffer, 1024, 0, NULL, NULL);
        if (n < 0) {
            perror("Receive failed");
            continue;
        }
        buffer[n] = '\0';
        printf("Server: %s\n", buffer);
    }
    close(sfd);
    return 0;
}
