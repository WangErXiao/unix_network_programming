#include <stdio.h>

int day_of_year(int year,int month,int day);
void month_day(int year,int yearday,int *pmonth,int *pday);

static char daytab[2][13]={
	{0,31,28,31,30,31,30,31,31,30,31,30,31},
	{0,31,29,31,30,31,30,31,31,30,31,30,31}
};

int main(){
	printf(" 2015 02 21  day of year is :%d \n",day_of_year(2015,2,21));
	int month=0;
	int day=0;

	month_day(2015,52,&month,&day);
	printf(" 2015 52  month day is : %d,%d \n",month,day);

	return 0;
}
int day_of_year(int year,int month,int day){
	int i,leap;
	leap=(year%4==0 && year %100!=0) || year%400==0;
	for(i=1;i<month;i++)
		day+=daytab[leap][i];
	return day;
}
void month_day(int year,int yearday,int *pmonth,int *pday){
	int i ,leap;
	leap=(year%4==0&&year%100!=0) || year%400==0;
	for(i=1;i<13;i++){
		*pday=yearday;
		*pmonth=i;
		yearday-=daytab[leap][i];
		if(yearday<1){
			break;			
		}
		printf("test---");
	}

}
