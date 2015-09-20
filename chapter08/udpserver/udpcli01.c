#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <arpa/inet.h>

#define MAXLINE 1024

void dg_cli(FILE *fp,int sockfd,struct sockaddr *pseraddr,socklen_t servlen);
int main(int argc,char **argv){
	int sockfd;
	struct sockaddr_in servaddr;
	if(argc !=2){
		printf("usage:udpcli <IPaddress>");
		exit(1);
	}	

	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_port=htons(9999);
	inet_pton(AF_INET,argv[1],&servaddr.sin_addr);
	
	sockfd=socket(AF_INET,SOCK_DGRAM,0);
	
	dg_cli(stdin,sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));	
	exit(0);	

}


void dg_cli(FILE *fp,int sockfd,struct sockaddr *pseraddr,socklen_t servlen){
	int n;
	char sendline[MAXLINE],recvline[MAXLINE+1];
	while(fgets(sendline,MAXLINE,fp)!=NULL){
		sendto(sockfd,sendline,strlen(sendline),0,pseraddr,servlen);	
		n=recvfrom(sockfd,recvline,MAXLINE,0,NULL,NULL);
		recvline[n]=0;
		fputs(recvline,stdout);
	}
}
