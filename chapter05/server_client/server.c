#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>

#define MAXLINE 1024

void str_echo(int sockfd);
int main(int argc,char **argv){
	int listenfd,connfd;
	pid_t childpid;
	socklen_t clilen;
	struct sockaddr_in cliaddr,servaddr;
	
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
	servaddr.sin_port=htons(9999);
	
	listenfd=socket(AF_INET,SOCK_STREAM,0);

	bind(listenfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
	listen(listenfd,256);
	
	for(;;){
		clilen=sizeof(cliaddr);
		connfd=accept(listenfd,(struct sockaddr *)NULL,NULL);
		if((childpid=fork())==0){
			close(listenfd);
			str_echo(connfd);		
			exit(0);
		}
		close(connfd);
	}

}

void str_echo(int sockfd){
	ssize_t n;
	char buf[MAXLINE];
	bzero(&buf,sizeof(buf));
	again:
		while((n=read(sockfd,buf,MAXLINE))>0){
			fputs(buf,stdout);
						
			write(sockfd,buf,sizeof(buf));

			bzero(&buf,sizeof(buf));
		}
		if(n<0 &&errno==EINTR)
			goto again;
		else if(n<0){
			perror("read error");
			exit(1);
		}
		
} 





