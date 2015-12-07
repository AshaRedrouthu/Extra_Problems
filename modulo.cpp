// Modulo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<conio.h>
int modulo(int x,int y,int a)
{
	int result=1;
	int sq=x;
	while(y>0)
	{
		if(y%2)
			result=result*sq;
		sq=(sq*sq)%a;
		y=y/2;
		if(result>a)
			result=result%a;
	}
	return result;
}

int _tmain(int argc, _TCHAR* argv[])
{
	unsigned int x,y,a;
	printf("eNTER x,y,a\n");
	scanf("%d %d %d",&x,&y,&a);
	int r = modulo(x,y,a);
	printf("%d",r);
	getch();
	return 0;
}

