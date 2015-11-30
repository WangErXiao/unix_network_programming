//
//  udp_listener.c
//  MAC_C
//
//  Created by yao on 15/11/30.
//  Copyright (c) 2015年 yao. All rights reserved.
//


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>


#define PORT "9999"
#define MAXBUFLEN 100

int main(void){
    
    int sockfd;
    
    int numbytes;
    
    struct addrinfo hints,*servinfo;
    
    struct sockaddr_storage their_addr;
    
    char buf[MAXBUFLEN];
    
    socklen_t addr_len;
    
    memset(&hints,0,sizeof(hints));
    
    hints.ai_family=AF_UNSPEC;
    hints.ai_socktype=SOCK_DGRAM;
    hints.ai_flags=AI_PASSIVE;
    
    getaddrinfo(NULL,PORT,&hints,&servinfo);
    
    sockfd=socket(servinfo->ai_family, servinfo->ai_socktype,servinfo->ai_protocol);
    
    bind(sockfd,servinfo->ai_addr,servinfo->ai_addrlen);
    
    freeaddrinfo(servinfo);
    
    printf("listener:waiting to recvfrom ...\n");

    while (1) {
        addr_len=sizeof(their_addr);
        recvfrom(sockfd, buf,MAXBUFLEN-1, 0, (struct sockaddr *)&their_addr, &addr_len);
    //buf[numbytes]='\0';
        printf("receive from client:%s\n",buf);
    }
    return 0;
}





