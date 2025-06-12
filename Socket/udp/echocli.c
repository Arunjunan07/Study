#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int sfd;
    char buffer[1024];
    struct sockaddr_in ser;

    sfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sfd < 0) {
        perror("Socket creation failed");
        exit(0);
    }

    memset(&ser, 0, sizeof(ser));
    ser.sin_family = AF_INET;
    ser.sin_port = htons(8080);
    ser.sin_addr.s_addr = inet_addr("127.0.0.1");

    printf("Enter message: ");
    scanf("%1023s", buffer);  
    
    sendto(sfd, buffer, strlen(buffer), 0, (struct sockaddr *)&ser, sizeof(ser));
    int n = recvfrom(sfd, buffer, 1024, 0, NULL, NULL);
    buffer[n] = '\0';
    printf("Server: %s\n", buffer);

    close(sfd);
    return 0;
}
