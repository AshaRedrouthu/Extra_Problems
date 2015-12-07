// ArraySorting.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<conio.h>
void count(int a[10],int n)
{
	for(int i=0;i<=n;i++)
	{
		if(a[i]==1){
			
			for(int j=n-1;j>i;j--)
			{
				
				if(a[j]==0)
				{
					int t=*(a+i);
					*(a+i)=*(a+j);
					*(a+j)=t;
					break;
				}
			}
		}
	}
	
	
}

int _tmain(int argc, _TCHAR* argv[])
{
	int n,count1=0,count2=0;
	int a[10];
	printf("Entre size of Array\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	count(a,n);
	for(int i=0;i<n;i++)
		printf("%d",a[i]);
	getch();
	return 0;
}

