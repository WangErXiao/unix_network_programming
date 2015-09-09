#include <stdio.h>

#define WARN_IF(EXP) do { if (EXP) \
		printf("Warning:" #EXP "\n"); } \
	while(0) 


int main(int argc, char *argv[]){
	
	int x=0;
	WARN_IF(x==0);

	return 0;
}
