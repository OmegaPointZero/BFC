#include <iostream>
#include <arpa/inet.h>

#include <netdb.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include "network.h"
#include <unistd.h>
#define MAX 80 
#define SA struct sockaddr 


using namespace std;

void func(int sockfd) 
{   /*
    char buff[MAX]; 
    int n; 
    for (;;) { 
        bzero(buff, sizeof(buff)); 
        printf("Enter the string : "); 
        n = 0; 
        while ((buff[n++] = getchar()) != '\n') 
            ; 
        write(sockfd, buff, sizeof(buff)); 
        bzero(buff, sizeof(buff)); 
        read(sockfd, buff, sizeof(buff)); 
        printf("From Server : %s", buff); 
        if ((strncmp(buff, "exit", 4)) == 0) { 
            printf("Client Exit...\n"); 
            break; 
        } 
    } 
    */
} 

int request(char dp[]){
    int sockfd, connfd;
    struct sockaddr_in servaddr, cli;
    char msg[256];
    char target[17];
    char port[6];
    int portnum;
    int i,j,k;
    for(i=0;i<17;i++){
        target[i] = (*dp);
        dp++;
    }
    for(j=0;j<6;j++){
        port[j] = *dp;
        dp++;
    }
    for(k=0;k<256;k++){
        msg[k] = *dp;
        dp++;
    }
    portnum = atoi(port);  
    
    //socket create and verfication
    sockfd = socket(AF_INET, SOCK_STREAM,0);
    if(sockfd == -1){
        printf("socket creation failed\n");
        exit(0);
    } /*
    else
        printf("Socket created successfully.\n");*/
    bzero(&servaddr, sizeof(servaddr));
    
    // assign IP and port
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(target);
    servaddr.sin_port = htons(portnum);

    // connect the client socket to server socket
    if(connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0){
        printf("Connection to server failed\n");
        exit(0);
    }
    else/*
        printf("connected to the server.\n");*/
        send(sockfd, msg, sizeof(msg), 0);

    func(sockfd);
    close(sockfd);


    return 0;
}

int recReq(){
    cout << "I'm here to recieve requests" << endl;
    return 0;
}
