#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>

#define MAXLINE 1024
void str_cli(FILE *fp,int sockfd);

int main(int argc,char **argv){
	int sockfd;
	struct sockaddr_in servaddr;
	
	if(argc !=2)
		fputs("usage:tcpcli <IPaddres>\n",stderr);	
	
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	
	bzero(&servaddr,sizeof(servaddr));
	
	servaddr.sin_family=AF_INET;
	
	servaddr.sin_port=htons(9999);
	
	inet_pton(AF_INET,argv[1],&servaddr.sin_addr);
	
	connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
	str_cli(stdin,sockfd);
		
	exit(0);
}

void str_cli(FILE *fp,int sockfd){
	char sendline[MAXLINE], recvline[MAXLINE];
	bzero(&sendline,MAXLINE);
	bzero(&recvline,MAXLINE);
	while(fgets(sendline,MAXLINE,fp) !=NULL){
		write(sockfd,sendline,strlen(sendline));
		if(read(sockfd,recvline,MAXLINE)==0){
			fputs("str_cli:server stop!!!",stderr);	
		}	
		fputs(recvline,stdout);		
	}
}



