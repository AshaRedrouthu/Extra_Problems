// dateprint.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
int strlength(char *date){
	int i=0;
	while(date[i]!='\0'){
		i++;
	}
	return i;
}
int validateDate(char *d,char *month,char *year){
int d1=0,m=0,y=0,i=0;
int month1[12]={31,29,31,30,31,30,31,31,30,31,30,31};
d1=(((d[0])-'0')*10)+(d[1]-'0');
m=(((month[0])-'0')*10)+(month[1]-'0');
y=(((year[0])-'0')*1000)+(((year[1])-'0')*100)+(((year[2])-'0')*10)+((year[3])-'0');
if(y % 4 != 0)
    month1[1]=28;
if(d1<=month1[m-1]&&m<=12)
    return 1;
   return 0;
}


void monthDis(char *month,char *result){
	char monthArr[13][15]={"","January","February","March","April","May","June","July","August","September","October","November","December"};
	int monthNum=(((month[0])-'0')*10)+(month[1]-'0');
	sprintf(result + strlength(result)," %s of",monthArr[monthNum]);
}
void dateDis(char *d,char *result){
	char ones[11][10]={"","First","Second","Third","Fourth","Fifth","Sixth","Seventh","Eight","Ninth","tenth"};
	char twos[10][20]={"","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
	char tens[5][10]={"","","Twenty","thirty"};
	int da=(((d[0])-'0')*10)+(d[1]-'0');
	if(da>10 && da<20)
		sprintf(result,"%sth",twos[d[1]-'0']);
	else if(da>=1&&da<=10)
		sprintf(result,"%s",ones[da]);
	else
		sprintf(result,"%s%s",tens[d[0]-'0'],ones[d[1]-'0']);

}
void yearDis(char *year,char *result){
	int l;
	int y=(((year[0])-'0')*1000)+(((year[1])-'0')*100)+(((year[2])-'0')*10)+((year[3])-'0');
	char ones[10][11]={"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
	char twos[15][15]={"","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
	char tens[11][15]={"Ten","Twenty","Thirty","Fourty","Fifty","Sixty","Seventy","Eighty","Ninty"};
	if(year[0]-'0'>0)
		sprintf(result+strlength(result)," %s Thousand ",ones[year[0]-'0']);
    if(year[1]-'0'>0)
		sprintf(result+strlength(result)," %s Hundred and ",ones[year[1]-'0']);
	if(year[2]-'0'==1)
		sprintf(result+strlength(result)," %s ",twos[year[2]-'0']);
	else{
		if(year[2]-'0'>1&&year[2]-'0'<10){
			sprintf(result+strlength(result),"%s ",tens[year[2]-'0'-1]);
		}
		sprintf(result+strlength(result),"%s ",ones[year[3]-'0']);
	}

}
void split_Date(char *date,char *d,char *month,char *year){
    int i=0,count=0;
	while(date[i]!='/')
		i++;
	if(i==2){
		d[0]=date[0];d[1]=date[1];d[2]='\0';
	}else{
		d[0]='0';
		d[1]=date[0];d[2]='\0';
	}
	i++;
	while(date[i]!='/')
	{	i++;count++;}
	if(count==2){
		month[0]=date[i-2];month[1]=date[i-1];month[2]='\0';
	}else{
		month[0]='0';count=0;
		month[1]=date[i-1];month[2]='\0';
	}
	i++;
	count=0;
	while(date[i]!='\0'){i++;count++;}
	if(count==4){year[0]=date[i-4],year[1]=date[i-3],year[2]=date[i-2],year[3]=date[i-1],year[4]='\0';}
	else if(count==3){year[0]='0',year[1]=date[i-3],year[2]=date[i-2],year[3]=date[i-1],year[4]='\0';}
	else if(count==2){year[0]='0',year[1]='0',year[2]=date[i-2],year[3]=date[i-1],year[4]='\0';}
	else{}
}
int _tmain(int argc, _TCHAR* argv[])
{
	char date[15],d[3],month[3],year[5],result[60];
	printf("Enter Date\n");
	scanf("%s",date);
	split_Date(date,d,month,year);
	if(validateDate(d,month,year)){
	dateDis(d,result);
	monthDis(month,result);
	yearDis(year,result);
	printf("%s",result);

	}
	else{
		printf("InValied Date");
	}
	getch();
	return 0;
}

