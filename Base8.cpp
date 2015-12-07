// Base-8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
void octalMinus(int num,int *a,int *i){
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



int _tmain(int argc, _TCHAR* argv[])
{
	int num;
	printf("Enter a Numbre\t");
	scanf("%d",&num);
	int *a;
	a=(int *) malloc(sizeof(int)*20);
	int i=0;
	octalMinus(num,a,&i);
	while(i>=0){
		printf("%d",a[i]);
		i--;
	}
	getch();
	return 0;
}

