// Permutations.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include<conio.h>
int numDigit(int num){
	int i=0;
	while(num>0){
		num=num/10;
		i++;
	}
	return i;
}
int numLess(int num,int num1){
	int i=0,r;
	while(num1 > 0){
		 r = num1 % 10;
		 if(r < num)
			i++;
		num1=num1 / 10;
		
	}
	return i;
}
int fact(int num){
	int f=1;
	int i=num;
	while(num > 0){
		f=f*num;
		num--;
	}
	return f;
}
int minRank(int num){
	int digit=1,r;
	int count=numDigit(num);
	int sum=0;
	while(count>1){
		r=1;
		for(int i=0;i<count-1;i++)
			r=r*10;
		int num1=num/r;
		num=num%r;
		count=numDigit(num);
		int less=numLess(num1,num);
		int fact1=fact(count);
		sum=sum+(less*(fact1));
		digit++;
	}
	return sum;
}
int _tmain(int argc, _TCHAR* argv[])
{
	int num;
	printf("Enter a number:");
	scanf("%d",&num);
	int index=minRank(num);
	printf("\nIndex: %d",index);
	getch();
	return 0;
}

