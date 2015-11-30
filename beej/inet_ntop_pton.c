#include <stdio.h>
#include <arpa/inet.h>
#include<stdlib.h>

int main(int argc,char **argv){
	char ip4[INET_ADDRSTRLEN];
	struct sockaddr_in sa;
        sa.sin_addr.s_addr=htonl(12722);	
	inet_ntop(AF_INET,&(sa.sin_addr),ip4,INET_ADDRSTRLEN);	
	printf("The IPv4 address is:%s\n",ip4);

	return 0;
}
