#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sig_chld(int signo){
	pid_t pid;
	int stat;
	pid=wait(&stat);
	printf("child %d terminated\n",pid);
	return;	
}

int main(){
	pid_t pid;
	if( signal(SIGCHLD,sig_chld)==SIG_ERR )
                printf("\n can't catch SIGCHLD\n");
	
	if((pid=fork())==0){
		sleep(5);
	}else{
		if((pid=fork())==0){
                	sleep(5);	
		}else{
			while(1)
				sleep(1);
		}
	}
	
	return 0;

}



