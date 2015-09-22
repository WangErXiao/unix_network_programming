#include <stdio.h>
#include <stdlib.h>
#include <signal.h> 
#include <unistd.h>

void alarmhandler(int sig){
	printf("alarm----------\n");
	return;
}
int main(int argc,char **argv){
	int num;
	if(argc!=2){
		printf("usage : <number> \n");
		exit(1);
	}
	num=atoi(*++argv);
	signal(SIGALRM,alarmhandler);
	if(alarm(4) !=0){
		printf("alarm was already set\n");
	}	
	sleep(num);
	alarm(0);
	printf("end-----------\n");
	return 0;	
}
