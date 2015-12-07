// StringMul.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "string.h"
#include "conio.h"
#include "malloc.h"

int retriveNum(char *str) {
	int num=str[strlen(str)-1]-'0';
	//printf("%d",num);
	if(num>0&&num<9)
		return num;
	else
		return 1;

}
void stringCon(char *str,int num){
	int count = 0;
	int j=strlen(str);
	int len=strlen(str);
	while(count<num-1){
		for(int k=0;k<len;k++){
			*(str+j)=*(str+k);
			j++;}
		count++;
		
	}
	str[j] = '\0';
	
}
void manuplate(char *str){
	int len=strlen(str);
	int num=retriveNum(str);
	str[len-1]='\0';
	str=(char *)realloc(str,sizeof(char)*(len-1)*(num-1));
	stringCon(str,num);	
}


int _tmain(int argc, _TCHAR* argv[])
{
	char *str;
	int i=0,len=0,x;
	printf("Enter lenght of string\n");
	scanf("%d",&len);
	str = (char *)malloc(sizeof(char) * len);
	printf("Enter string\n");
	scanf("%s",str);
	int num=retriveNum(str);
	if(num!=1)
		manuplate(str);
	len = strlen(str);
	while(str[i] != '\0') {
	  printf("%c",*(str+i));
	  i++;
	}

	
	getch();
	return 0;
}

