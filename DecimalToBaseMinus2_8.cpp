// DecimalToBaseMinus(2)(8).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <conio.h>
#include <malloc.h>
void MinusEight(int num,int *a,int *i){
int num1=num;
int j=*i;
while(!(num>0&&num<8)){
	if(num<0&&num>-8)
		num1=1;
	else
		num1=num1/-8;
	a[j]=num-(num1*(-8));
	num=num1;
	j++;
}
a[j]=num1;
*i=j;

}


void MinusTwo(int num,int *a,int *i){
int num1=num;
int j=*i;
while(num!=1)
{
    if(num1>0||num1%-2==0)
		num1=num1/-2;
	else
		num1=(num1/-2)+1;
	a[j]=num-(num1*(-2));
	num=num1;
	j++;
}
a[j]=num1;
*i=j;

}

int _tmain(int argc, _TCHAR* argv[])
{
	int num;
	printf("Enter a Numbre\t");
	scanf("%d",&num);
	int *eight,*two;
	eight=(int *) malloc(sizeof(int)*20);
	two=(int *) malloc(sizeof(int)*20);
	int i=0;
	MinusTwo(num,two,&i);
	printf("\nBaseMinus2:");
	while(i>=0){
		printf("%d",two[i]);
		i--;
	}
	i=0;
	MinusEight(num,eight,&i);
	printf("\nBaseMinu8:");
	while(i>=0){
		printf("%d",eight[i]);
		i--;
	}
	getch();
	return 0;
	return 0;
}

