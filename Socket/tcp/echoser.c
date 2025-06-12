#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int sfd, cfd;
    struct sockaddr_in ser;
    int addrlen = sizeof(ser);
    char buffer[1024] = {0};

    if ((sfd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
        perror("socket failed");

    ser.sin_family = AF_INET;
    ser.sin_addr.s_addr = INADDR_ANY;
    ser.sin_port = htons(8080);

    if (bind(sfd, (struct sockaddr *)&ser, sizeof(ser)) < 0){
        perror("bind failed");
        exit(0);
    }

    if (listen(sfd, 3) < 0)
        perror("listen");
     
    if ((cfd = accept(sfd, (struct sockaddr *)&ser, (socklen_t*)&addrlen)) < 0)
        perror("accept failed");

    int val = read(cfd, buffer, 1024);
    if (val < 0) {
        perror("read failed");
        close(cfd);
    }
    printf("Received message: %s\n", buffer);
    send(cfd, buffer, val, 0);
    close(cfd);
    
    return 0;
}
