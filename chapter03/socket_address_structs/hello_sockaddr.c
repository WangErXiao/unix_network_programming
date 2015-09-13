#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(){
	struct sockaddr saddr;
	struct sockaddr_in *saddr_in=(struct sockaddr_in *)&saddr;
	inet_aton("0.0.0.255",&(saddr_in->sin_addr));
	printf("Hello %s\n",inet_ntoa(saddr_in->sin_addr));	
	return 0;
}
