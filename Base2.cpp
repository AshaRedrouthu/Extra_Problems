// Base-2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
void binary(int num,int *a,int *i){
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
	int *a;
	a=(int *) malloc(sizeof(int)*20);
	int i=0;
	binary(num,a,&i);
	while(i>=0){
		printf("%d",a[i]);
		i--;
	}
	getch();
	return 0;
}

