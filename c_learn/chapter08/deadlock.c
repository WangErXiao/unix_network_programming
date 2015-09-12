#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

pthread_mutex_t lock1,lock2;

void* func1(void* data){
	pthread_mutex_lock(&lock1);
	sleep(1);
	pthread_mutex_lock(&lock2);
	printf("Function One\n");
	pthread_mutex_unlock(&lock1);
	pthread_mutex_unlock(&lock2);
	pthread_exit(NULL);
}
void* func2(void* data){
	pthread_mutex_lock(&lock2);
	sleep(1);
	pthread_mutex_lock(&lock1);
	printf("Function One\n");
	pthread_mutex_unlock(&lock1);
	pthread_mutex_unlock(&lock2);
	pthread_exit(NULL);
}

int main(){

	pthread_t t1,t2;
	pthread_mutex_init(&lock1,NULL);
	pthread_mutex_init(&lock2,NULL);
	
	pthread_create(&t1,NULL,func1,NULL);
	pthread_create(&t2,NULL,func2,NULL);

	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	
	return 0;
}
