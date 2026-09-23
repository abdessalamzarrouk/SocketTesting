#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>
#include <stdlib.h>

#define PORT "3490"
#define BACKLOG 10
#define BUFFER_LENGTH 100

int main(int argc, char *argv[])
{
    struct sockaddr_storage their_addr;
    socklen_t addr_size;

	int sockfd, new_fd;
    struct addrinfo hints, *res;

    struct sockaddr_in* peeraddr;

    char *errormsg;

    char buffer[BUFFER_LENGTH];

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    getaddrinfo(NULL, PORT, &hints, &res);

    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    
    if(bind(sockfd, res->ai_addr, res->ai_addrlen) != 0) {
        errormsg = strerror(errno);
        printf("Bind function error code : %s \n", errormsg);
        exit(-1);
    };

    if(listen(sockfd, BACKLOG) != 0) {

        errormsg = strerror(errno);

        printf("Listen function error code : %s \n", errormsg);
        exit(-1);
    }

    addr_size = sizeof(their_addr);
    new_fd = accept(sockfd, (struct sockaddr*)&their_addr, &addr_size);

    if(new_fd == -1) {

        errormsg = strerror(errno);

        printf("Accept function error code : %s \n", errormsg);
        exit(-1);
    }

    char* msg_sent = "Hello World!";
    int len, bytes_sent;

    len = strlen(msg_sent);
    bytes_sent = send(new_fd, msg_sent, len, 0);

    if(bytes_sent == -1) {
        errormsg = strerror(errno);

        printf("Send function error code : %s \n", errormsg);
        exit(-1);
    }



    // FIX LATER
    //socklen_t size = sizeof( struct sockaddr );

   /*if(getpeername(new_fd, (struct sockaddr*)peeraddr, &size) == -1) {
        errormsg = strerror(errno);
        printf("getpeername function error message : %s \n", errormsg);
        exit(-1);
    }  */

    //inet_ntop(AF_INET, peeraddr, buffer, BUFFER_LENGTH);

    //printf("IP ADDRESS OF PEER IS: %s \n", buffer);


    close(sockfd);
    
	freeaddrinfo(res); // free the linked list

	return 0;
}

