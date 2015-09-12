#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#define MAX_COUNT 200

void ChildProcess(void);
void ParentProcess(void);

int main(){

	pid_t pid;
	pid=fork();
	if(pid==0)
		ChildProcess();
	else
		ParentProcess();

	return 0;
}

void ChildProcess(void){
	int i;
	for(i=1;i<=MAX_COUNT;i++){
		printf(" This line is from child,value=%d\n",i);			
		sleep(1);
	}
	printf("  *** Child process is done ***\n");

}


void ParentProcess(void){
	int i;
	for(i=1;i<=MAX_COUNT;i++){
		printf(" This line is from parent,value=%d\n",i);			
		sleep(1);
	}
	printf("  *** Parent process is done ***\n");

}


