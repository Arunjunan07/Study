#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int sfd;
    char buffer[1024];
    struct sockaddr_in ser, cli;
    socklen_t addr_len = sizeof(cli);

    sfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sfd < 0) 
        perror("Socket creation failed");
        
    memset(&ser, 0, sizeof(ser));
    ser.sin_family = AF_INET;
    ser.sin_addr.s_addr = INADDR_ANY;
    ser.sin_port = htons(8080);

    if (bind(sfd, (const struct sockaddr *)&ser, sizeof(ser)) < 0) {
        perror("Bind failed");
        close(sfd);
    }
    
    int n = recvfrom(sfd, buffer, 1024, 0, (struct sockaddr *)&cli, &addr_len);
    buffer[n] = '\0';
    printf("Client: %s\n", buffer);
    sendto(sfd, buffer, n, 0, (struct sockaddr *)&cli, addr_len);

    close(sfd);
    return 0;
}