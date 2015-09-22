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

void str_echo(int connfd){
	ssize_t n;
        char buf[MAXLINE];
        bzero(&buf,sizeof(buf));
        while((n=read(connfd,buf,MAXLINE))>0){
                        fputs(buf,stdout);
                        write(connfd,buf,sizeof(buf));
                        bzero(&buf,sizeof(buf));
        }
}

int main(int argc,char **argv){
	int listenfd,connfd;
	char *UNIXSTR_PATH;
	UNIXSTR_PATH= *++argv;
	pid_t childpid;	
	socklen_t clilen;
	struct sockaddr_un cliaddr,servaddr;
	listenfd=socket(AF_LOCAL,SOCK_STREAM,0);
	unlink(UNIXSTR_PATH);
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sun_family=AF_LOCAL;
	strcpy(servaddr.sun_path,UNIXSTR_PATH);
	bind(listenfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
	
	listen(listenfd,256);
	
	for(;;){
		clilen=sizeof(cliaddr);
		if((connfd=accept(listenfd,(struct sockaddr *)&cliaddr,&clilen))<0){
			
			if(errno==EINTR)
				continue;	
			else{
				printf("accept error\n");
				exit(1);
			}
		}		
		if((childpid=fork())==0){
			close(listenfd);
			str_echo(connfd);
			exit(0);	
		}
		close(connfd);
	}

	return 0;
	
}
