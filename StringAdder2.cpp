// StringAdder2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "conio.h"
void adder(char *a,char *b,char *c){
	int i=0,carry=0;
	while(a[i]!='\0'){
		int sum=a[i]-'0'+b[i]-'0';
		carry=sum/10;
		if(i==0)
			c[i]=sum+'0';
		else{
			int j=i;
			if(carry){
				c[j]=sum%10+'0';
				while(j>=0){
					int num=c[j-1]-'0'+carry;
					if(num>9){
						c[j-1]=num%10+'0';
						carry=num/10;
					}
					else{
						c[j-1]=num+'0';
						break;
					}
					j--;}
			}
			else{
				c[j]=sum+'0';
			}
		}
		i++;}
	c[i]='\0';
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

