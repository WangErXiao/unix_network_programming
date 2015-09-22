#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <sys/un.h>

#define MAXLINE 1024

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

int main(int argc,char **argv){
	
	int sockfd;
	struct sockaddr_un seraddr;
	sockfd=socket(AF_LOCAL,SOCK_STREAM,0);
	bzero(&seraddr,sizeof(seraddr));
	seraddr.sun_family=AF_LOCAL;
	strcpy(seraddr.sun_path,*++argv);
	connect(sockfd,(struct sockaddr *)&seraddr,sizeof(seraddr));
	str_cli(stdin,sockfd);
	exit(0);	
}
