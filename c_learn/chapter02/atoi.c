#include <stdio.h>
#include <stdbool.h>
#include <math.h>

double atoi(char s[] );
int main(){
	printf("please enter a number string:\r\n");
	char s[1024];
	scanf("%s",s);
	printf("the result is : %f \r\n", atoi(s));
	return 0;
}

double atoi(char s[]){
	double n=0;
	int i,l;
	l=0;
	bool isDot=false;
	for(i=0; s[i]>='0' & s[i] <= '9' || s[i]=='.'; ++i ){
		if(s[i]=='.'){
			if(isDot==true){
				break;
			}else{
				isDot=true;
				continue;
			}
		}
		n =10*n +(s[i]-'0');
		if(isDot==true){
			l++;
		}
	}
	return n/pow(10,l);
}
