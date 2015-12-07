// ArrayMul.cpp : Defines the entry point for the console application.
//
/*Multiplication Of TWO ARRAYS*/

#include "stdafx.h"
#include<conio.h>
#include<stdlib.h>
void insert(int a[10],int c[10],int n){
	int mul=1,pro=1,b[10];
	for(int i=n-1;i>=0;i--){
		mul=mul*a[i];
		*(b+i)=mul;
	}
	for(int i=0;i<n;i++){
		if(i==0){
			c[i]=b[i+1];
			pro = a[i];
		}
		else if(i==n-1){
			c[i]=pro;
		}
		else{
			c[i]=b[i+1]*pro;
			pro=pro*a[i];
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a[10],c[10],n;
	printf("Enter Size of array");
	scanf("%d",&n);
	printf("Enter array elements\n");
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	insert(a,c,n);
	for(int i=0;i<n;i++)
		printf("%d\t",c[i]);
	getch();
	return 0;
}

