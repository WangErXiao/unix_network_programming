#include <stdio.h>

#define MAX_DATA 100

typedef enum EyeColor{
	BLUE_EYES,GREEN_EYES,BROWN_EYES,
	BLACK_EYES,OTHER_EYES
} EyeColor;

const char *EYE_COLOR_NAMES[]={
	"Blue","Green","Brown","Black","Other"
};

typedef struct Person{
	int age;
	char first_name[MAX_DATA];
	char last_name[MAX_DATA];
	EyeColor eyes;
	float income;	
}Person;

int main(int argc,char *argv[]){
	Person you={.age=0};
	int i=0;
	char *in=NULL;
	printf("What's your First Name?");
	in=fgets(you.first_name,MAX_DATA-1,stdin);
	if(in ==NULL){
		printf("Failed to read last name.\n");
		return -1;
	}
	printf("How old are you?\n");
	
	int rc=fscanf(stdin,"%d",&you.age);
	
	if(rc<=0){
		printf("You have to enter a number.\n");
		return -1;
	}
	
	printf("What color are your eyes:\n");
	
	for(i=0;i<=OTHER_EYES;i++){
		printf("%d) %s\n",i+1,EYE_COLOR_NAMES[i]);
	}
	printf("> ");
	
	int eyes=-1;
	rc=fscanf(stdin,"%d",&eyes);
	if(rc<=0){
		printf("You have to enter a number.");	
		return -1;
	}
	you.eyes=eyes-1;
	eyes-=1;
	if( eyes >OTHER_EYES || eyes < 0  ){
		printf("Do it right,that's not an option.");	
		return -1;
	}
	printf("How much do you make an hour?");
	rc=fscanf(stdin,"%f",&you.income);

	if(rc<=0){
		printf("Enter a floating point number.");	
		return -1;
	}
	printf("--------RESULTS---------\n");
	printf("First Name:%s\n",you.first_name);
	printf("Last Name: %s\n",you.last_name);
        printf("Eyes: %s\n", EYE_COLOR_NAMES[you.eyes]);
	printf("Age:%d\n",you.age);
	printf("Income:%f\n",you.income);
	return 0;


}
