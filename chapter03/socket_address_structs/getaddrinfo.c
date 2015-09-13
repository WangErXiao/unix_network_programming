#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(){
	char hostname[]="www.usna.edu";
	struct addrinfo *result;
	struct addrinfo hints;
	struct sockaddr_in *saddr;
	int s;
	memset(&hints,0,sizeof(struct addrinfo));
	hints.ai_family=AF_INET;
	
	if((s=getaddrinfo(hostname,NULL,&hints,&result))!=0){
		fprintf(stderr,"getaddrinfo:%s\n",gai_strerror(s));
		exit(1);
	}
	saddr=(struct sockaddr_in *) result->ai_addr;
	printf("Hello %s\n",inet_ntoa(saddr->sin_addr));
	freeaddrinfo(result);
	return 0;
}
