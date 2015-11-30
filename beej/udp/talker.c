//
//  talker.c
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


int main(int argc,char *argv[]){

    int sockfd;
    struct addrinfo hints,*servinfo;
    if(argc!=3){
        fprintf(stderr,"usage:talker hostname message\n");
        
        exit(1);
    }
    memset(&hints,0,sizeof(hints));
    
    hints.ai_family=AF_UNSPEC;
    
    hints.ai_socktype=SOCK_DGRAM;
    
    getaddrinfo(argv[1], PORT, &hints, &servinfo);
    
    sockfd=socket(servinfo->ai_family,servinfo->ai_socktype,servinfo->ai_protocol);
    
    sendto(sockfd,argv[2],strlen(argv[2]),0,servinfo->ai_addr,servinfo->ai_addrlen);
    
    freeaddrinfo(servinfo);
    
    close(sockfd);
    return 0;
}













