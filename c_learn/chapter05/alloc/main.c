#include <stdio.h>
#include "alloc.h"

int main(){
	printf("please input size of char array:\n");
	int size;
	scanf("%d",&size);
	char *p= alloc(size);
	for(int i=0;i<size;i++){
		*p='c';
		p++;
	}
	printf("result is: %s\n",p-size);
	afree(p);
	
	return 0;
}
