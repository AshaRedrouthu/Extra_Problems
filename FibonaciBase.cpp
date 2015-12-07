// FibonaciBase.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <conio.h>
#include <malloc.h>
void generateFibboArray(int *a,int num,int *j){
	int sum=0,a1=0,b1=1,c=1,i=1,flage=0;
	while(sum<=num){
		a=(int *)realloc(a,sizeof(int)*i);
		a[i-1]=c;
		sum=sum+c;
		c=a1+b1;
		a1=b1;
		b1=c;
		i++;
	}
	*j=i-1;
}
void generateFibboSeries(int *a,int *b,int num,int *k){
	int sum=0,i=0,flage=0;
	while(sum<num){
		sum=sum+a[i];
		i++;
		if(sum>=num){
			i=i-1;
			if(flage==0)
				*k=i;
			flage=1;
			b[i]=1;
			num=num-a[i];
			sum=0;
			i=0;
		}
		}

	for(int i=0;i<= *k;i++)
	{
		if(b[i]!=1)
			b[i]=0;
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	int *a,*b,num,j,k=0;
	printf("Enter A Number\t");
	scanf("%d",&num);
	a=(int *)malloc(sizeof(int)*10);
	generateFibboArray(a,num,&j);
	b=(int *)malloc(sizeof(int) * j);
	generateFibboSeries(a,b,num,&k);
	for(int i=0;i<=k;i++)
	printf("%d",b[i]);

	getch();
	return 0;
}

