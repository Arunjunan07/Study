#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int sfd, cfd;
    struct sockaddr_in addr;
    int len = sizeof(addr);
    char buffer[1024] = {0};

    if ((sfd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
        perror("socket failed");

    // Set up the server address (localhost, port 8080)
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(8080);

    if (bind(sfd, (struct sockaddr *)&addr, sizeof(addr)) < 0)
        perror("bind failed");
    
    if (listen(sfd, 3) < 0)
        perror("listen failed");

    printf("Server is listening on port %d...\n", 8080);

    if ((cfd = accept(sfd, (struct sockaddr *)&addr, (socklen_t*)&len)) < 0)
        perror("accept failed");

    printf("Client connected!\n");

    while (1) {
        int val = read(cfd, buffer, 1024);
        if (val == 0) {
            printf("Client disconnected.\n");
            break;
        }
        buffer[val] = '\0';
        printf("Client: %s\n", buffer);

        printf("Server: ");
        scanf("%[^\n]%*c", buffer);
        send(cfd, buffer, strlen(buffer), 0);
    }
    close(cfd);
    close(sfd);

    return 0;
}