#include<stdio.h>
int main()
{
	int year,month,tbd;
	scanf("%d %d",&year,&month);
	if((year % 400 == 0 || ( year % 4 == 0 && year % 100 != 0)) && month == 2){
		printf("29\n",tbd);
	}else if(year % 400 == 0 || ( year % 4 == 0 && year % 100 != 0) && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)){
		printf("31\n",tbd);
	}else if(year % 400 == 0 || ( year % 4 == 0 && year % 100 != 0) && (month == 4 || month == 6 || month == 9 || month == 11)){
		printf("30\n",tbd);
	}else if(year % 400 != 0 && month == 2){
		printf("28\n",tbd);
	}else if(year % 400 != 0 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)){
		printf("31\n",tbd);
	}else if(year % 400 != 0 && (month == 4 || month == 6 || month == 9 || month == 11)){
		printf("30\n",tbd);
	}
	return 0;
}
