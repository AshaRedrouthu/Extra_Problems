// BaseMinus(2)ToMinus(8).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
int strlength(char *two){
	int i=0;
	while(two[i]!='\0')
		i++;
	return i;
}
int power(int a,int b){
	int i=1,pow=1;
	if(b)
		pow=a;

	while(i<b){
		pow=pow*a;
		i++;
	}
	return pow;
}
int convert(char *two,int len,char *eight)
{
	int i=len-1,qus=0,rem=0,j=0,num,qus1=0,rem1=0,qus2=0,rem2=0;
	while(i>=0)
	{
		if(two[i]-'0'){
			num=power(-2,j);
			qus=qus+(num/(-8));
			rem=rem+(num%(-8));
			}
		j++;
		i--;
	}
	if(qus>= -8 && qus <0 || rem >= -8 && rem <0){
	if(qus>= -8&& qus <0){
		qus1=1;rem1 = 8+qus;}
	else
		qus1=qus;

	if(rem >= -8 && rem <0){
		qus2=1;rem2=8+rem;} 
		else
			rem2=rem;
   len=(qus1*100)+((qus2+rem1)*10)+(rem2);
	}
	else
		len = (qus * 10) + rem;
	return len;	

}

			


int _tmain(int argc, _TCHAR* argv[])
{
	char *two,*eight;
	two=(char *) malloc(sizeof(char)*20);
	eight=(char *)malloc(sizeof(char)*20);
	printf("EnterBaseMinusTwoValue:");
	scanf("%s",two);
	int len=strlength(two);
	printf("%d",convert(two,len,eight));
	getch();
	return 0;
}

