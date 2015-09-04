#include <stdio.h>

enum boolean {NO,YES};
enum months {JAN=1,FEB,MAR,APR,MAY,JUN,JUL,AUG,SEP,OCT,NOV,DEC};

int main(){
	printf("the value of NO enum is:%d\r\n",NO );
	printf("the value of NO enum is:%d\r\n",YES);
	
	printf("the value of DEC enum is:%d\r\n",DEC);
	return 0;
}
