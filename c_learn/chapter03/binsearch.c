#include <stdio.h>

int binsearch(int x, int v[],int n);

int main(){
	int aim;
	int b[10];
	int number;
	printf("please input ten sorted number from little to big :\r\n");	
 
	for(int i=0;i<10;i++){
		scanf("%d",&number);
		b[i]=number;
	}
	printf("please input aim  number :\r\n");	
	scanf("%d",&aim);
	printf("the index of aim is :%d \r\n",binsearch(aim,b,10));
	return 0;
}

int binsearch(int x, int v[],int n){
	int low=0;
	int high=n-1;
	int mid;
	while(low<=high){
		mid=(low+high)/2;
		if(x<v[mid]){
			high=mid+1;
		}else if(x>v[mid]){
			low=mid+1;	
		}else{
			return mid;
		}
	}
	return -1;
}
