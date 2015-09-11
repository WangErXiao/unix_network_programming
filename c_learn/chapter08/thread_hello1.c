#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void* say_hello(void* data){
	char *str;
	str=(char*)data;
	int count=5;
	while(count--){
		printf("current %s count is%d\n",str,count);
		sleep(1);
	}
	pthread_exit(NULL);
}

int main(){

	pthread_t t1,t2;
	
	pthread_create(&t1,NULL,say_hello,"thread one");
	pthread_create(&t2,NULL,say_hello,"thread two");
	
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	printf("The program end.......... bye\n");
	return 0;
}
