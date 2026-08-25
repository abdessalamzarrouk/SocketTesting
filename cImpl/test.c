#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

void main(char* args) {
    struct sockaddr_in sa;

    inet_pton(AF_INET,"192.168.3.23",&(sa.sin_addr));

    char ip4[INET_ADDRSTRLEN];// space to hold the IPv4 string

    inet_ntop(AF_INET, &(sa.sin_addr), ip4, INET_ADDRSTRLEN);

}