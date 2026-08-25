#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int sockfd;
    struct addrinfo hints, *res;

    char *errormsg;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    getaddrinfo(NULL, "3490", &hints, &res);

    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

    
    if(bind(sockfd, res->ai_addr, res->ai_addrlen) != 0) {
        errormsg = strerror(errno);

        printf("Bind function error code : %s \n", errormsg);
        exit(-1);
    };

    if(listen(sockfd,5) != 0) {

        errormsg = strerror(errno);

        printf("Listen function error code : %s \n", errormsg);
        exit(-1);
    }
    
	freeaddrinfo(res); // free the linked list

	return 0;
}

