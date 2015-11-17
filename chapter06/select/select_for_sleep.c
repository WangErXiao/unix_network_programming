#include <sys/select.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>

int  main(){
	struct timeval tv;
	struct timeval start,stop;
	tv.tv_sec=2;
	tv.tv_usec=50000;
	gettimeofday(&start,NULL);
	select(1,NULL,NULL,NULL,&tv);
	gettimeofday(&stop,NULL);
	printf("took %ld\n",stop.tv_usec+1000000*stop.tv_sec-
	start.tv_sec*1000000-start.tv_usec);
	return 0;
}
