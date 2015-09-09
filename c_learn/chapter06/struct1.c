#include <stdio.h>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
struct point{
	int x;
	int y;
};
struct rect{
	struct point pointX;
	struct point pointY;
};

struct rect cannorect(struct rect r){
	struct rect temp;
	
	temp.pointX.x=min(r.pointX.x,r.pointY.x);
	temp.pointX.y=min(r.pointX.y,r.pointY.y);
	
	temp.pointY.x=max(r.pointX.x,r.pointY.x);
	temp.pointY.y=max(r.pointX.y,r.pointY.y);

	return temp;
}

int main(){
	struct point px;
	struct point py;
	px.x=6;
	px.y=2;
	
	py.x=3;
	py.y=4;
	
	struct rect r;
	r.pointX=px;
	r.pointY=py;
	
	r=cannorect(r);

	printf("rect r.X.x : %d\n",r.pointX.x);
	printf("rect r.Y.y : %d\n",r.pointY.y);
	
	return 0;
}
