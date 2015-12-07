// gen_UsignedString.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "conio.h"
int strlength(char *p){
	int i=0;
	while(p[i]!='\0'){
		i++;
	}
	return i;
}

void genString(char *p,int k,char *q)
{
    int i=1;
    int l=0;
    while(i<=k){
		if(i==1)
            sprintf(q,"%s",p);
		else
			sprintf(q +strlength(q),"%s",p);
        i++;
    }
}
int divisible_11(char *p,int k)
{
	int odd = 0,even=0;
	int l=strlength(p);
    int i=l-1;
	if(l==1&&!(k%2)){
		return 1;
	}
	while(i>=0)
    {
        odd = odd+p[i]-'0';
        if(i>0)
            even = even + p[i-1]-'0';
        i=i-2;
    }  
	return !((odd-even)%11);
}

int _tmain(int argc, _TCHAR* argv[])
{
	char p[100],q[100];
    int k;
    printf("Enter unsigned integer:\t");
    scanf("%s",p);
    printf("\nEnter a number");
    scanf("%d",&k);
    genString(p,k,q);
   // printf("\n%s",q);
	if(divisible_11(p,k))
		printf("\n%s Divisible by 11",q);
	else
		printf("\n%s Not divisible by 11",q);
   getch();
	return 0;
}

