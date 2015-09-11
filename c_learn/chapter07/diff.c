#include <stdio.h>
#include <stdlib.h>

int main(int argc ,char *argv[]){
	if(argc !=3){
		printf("arguments error!!\n");
		exit(2);
	}
	FILE *f1;
	FILE *f2;

	f1=fopen(*++argv,"r");
	f2=fopen(*++argv,"r");
	
	char l1[100];
	char l2[100];
	char *tmp;
	char *tmp1;
	int count=0;
	for(  ; fgets(l1,100,f1)!=NULL && fgets(l2,100,f2)!=NULL; ){
		count++;
		tmp=l1;	
		tmp1=l2;
		while( *++tmp != *++tmp1 ){
			printf("diff line %d: %s\n",count, tmp);	
			break;
		}
	}
	
	fclose(f1);
	fclose(f2);
	return 0;
}
