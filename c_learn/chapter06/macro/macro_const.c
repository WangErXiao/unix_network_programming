#define BUFFER_SIZE 1024
#define NUMBERS 1, \
		2,\
		3

#define min(x,y) ((x)<(y)?(x):(y))

int main(){
	int x[]={NUMBERS};		
	int length=sizeof(x)/sizeof(int);
	for(int i=0;i<length;i++){
		printf("%d \t",x[i]);
	}
	printf("\n");	
	
	return 0;
}
