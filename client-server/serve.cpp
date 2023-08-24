#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

using namespace std;

void error(char *msg){
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]){
    if(argc < 2) printf("enter port no");

    int sockfd, newsockfd, port, n, nRet = 0;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[1000];
    socklen_t clilen;
    fd_set fr, fw, fe;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd < 0) printf("Socket Busy\n");
    else cout << "Socket Created \n";
    port = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    memset(&(serv_addr.sin_zero), 0, 8);

    nRet = bind(sockfd, (sockaddr *) &serv_addr, sizeof(sockaddr));

    if(nRet < 0) printf("bind failed\n");
    else cout << "Bind Success\n";

    nRet = listen(sockfd, 5);
    if(nRet < 0){
        printf("listen unsuccessful\n");
    }
    else cout << "listen success\n";
    return 0;
}