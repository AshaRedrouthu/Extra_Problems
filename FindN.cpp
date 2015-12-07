// FindN.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <conio.h>
int findN(int *a){
	int i=0,n=0,n1=1;
	while(a[n]<a[n1*2])
	{
		n=n1*2;
		n1=n1*2;
	}
	return n-1;
}


int _tmain(int argc, _TCHAR* argv[])
{
	int a[30];
	printf("enter array elements\n");
	for(int i=0;i<10;i++)
		scanf("%d",&a[i]);
	int n=findN(a);
	printf("\nn value:%d",n);
	getch();
	return 0;
}

