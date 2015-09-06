#include <stdio.h>

void swap(int *px, int *py);
int main(){
	int x;
	int y;
	printf("\r please input two number : \n");
	
	scanf("%d",&x);
	scanf("%d",&y);
	
	swap(&x,&y);
	
	printf("\r the result is  : %d , %d  \n",x,y);
	return 0;

}
void swap(int *px, int *py){
	int tmp= *px;
	*px=*py;
	*py=tmp;
}
