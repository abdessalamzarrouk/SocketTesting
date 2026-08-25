#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>
#include <stdlib.h>

#define PORT "3490"
#define BACKLOG 10
#define SIZE_STR 100

int main(int argc, char *argv[])
{
    char* msg_returned;

	int sockfd;
    struct addrinfo hints, *res;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    getaddrinfo(NULL, PORT, &hints, &res);

    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

    connect(sockfd, res->ai_addr, res->ai_addrlen);

    recv(sockfd, msg_returned, SIZE_STR, 0);

    printf("MESSAGE RETURNED IS %s \n", msg_returned);

	freeaddrinfo(res); // free the linked list

	return 0;
}

