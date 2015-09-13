#include<stdio.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int main(){
	struct in_addr addr;
	unsigned char *ip;
	ip=(unsigned char*) & (addr.s_addr);
	ip[0]=10;
	ip[1]=4;
	ip[2]=32;
	ip[3]=41;	
	printf("Hello %s\n",inet_ntoa(addr));
	
	inet_aton("255.255.255.255",&addr);
	printf("Hello %u\n",addr.s_addr);
	return 0;
}
