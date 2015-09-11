#include <unistd.h>

int main(){
	char str[100];

	write(1,"\n Type Something :",17);

	read(0,str,100);
	
	write(1,"\nYou typed:\n",13);
	
	write(1,str,100);
	write(1,"\n",10);
}
