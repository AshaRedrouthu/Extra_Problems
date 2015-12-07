// gen_UsignedString_3.cpp : Defines the entry point for the console application.
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
int divisible_3(char *p,int k)
{
	int sum = 0,result=0;
	int l=strlength(p);
    int i=l-1;
	while(i>=0)
    {
       sum+=p[i]-'0';
	   i--;
    }  
	if(!(sum%3))
		return result;
	if(sum%3 && k%3==0)
		return result;
	return 1;
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
	if(!divisible_3(p,k))
		printf("\n%s Divisible by 3",q);
	else
		printf("\n%s Not divisible by 3",q);
   getch();
	return 0;
}


