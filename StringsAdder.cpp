// StringsAdder.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "conio.h"
#include "malloc.h"
int strlength(char *p){
	int i=0;
	while(p[i]!='\0'){
		i++;
	}
	return i;
}

void adder(char *a,char *b,char *c)
{
	int i=strlength(a)-1;
	int j=strlength(b)-1;
	int num,k=0;
	int carry=0;
	while(i>=0&&j>=0){
	    num=(a[i]-'0')+(b[j]-'0')+carry;
		carry=num/10;
		c[k]=num%10+'0';
		i--,j--,k++;
	}
	
	while(i<0&&j>=0){
		num=(b[j]-'0')+carry;
		carry=num/10;
		c[k]=num%10+'0';
		j--,k++;
	}
	
	while(i>=0&&j<0){
		num=(a[i]-'0')+carry;
		carry=num/10;
		c[k]=num%10+'0';
		i--,k++;
	}
	if(carry){
		c[k]=carry+'0';
		k++;
	}
	c[k]='\0';
	i=0,k=k-1;
	while(i<k)
	{
		char ch = c[i];
		c[i]=c[k];
		c[k]=ch;
		i++,k--;
	
}
}
int _tmain(int argc, _TCHAR* argv[])
{
	char a[10],b[10],c[10];
	int i=0;
	printf("Enter first number\t");
	scanf("%s",a);
	printf("\nEnter secnod number\t");
	scanf("%s",b);
	adder(a,b,c);
	printf("\n%s",c);
    getch();
	return 0;
}

