/*Given three numbers n1,n2,and r. Merge the table of n1 and n2 and find the r th number. In merging it should eliminate duplicate values (tables consists the multiples of those numbers ,ie 3 contains 3,6,9,12..)
Ex , n1=3 ,n2=5 and r=5, The merged table is 3,5,9,10,12,15(One more 15 is removed as its duplicate ) 18,20,21,24,25........so on .

The rth num ie 5th number is 12 ,so OP is 12

*/

#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node *next;
};
int create(int num1,int num2,int r,struct node *start)
{
    int i=1,k=1;
    struct node *ptr=NULL,*newnode1,*newnode2;
    while(i<=r)
    {
        if(start==NULL){
            newnode1=(struct node *)malloc(sizeof(struct node));
            newnode1->data=num1*k;
            newnode1->next=NULL;
            start=newnode1;
            ptr=start;
            i++;
        }
        else{
            newnode2=(struct node *)malloc(sizeof(struct node));
            newnode2->data=num2*k;
            newnode2->next=NULL;
            ptr->next=newnode2;
            ptr=newnode2;
            k++;
            i++;
            if(i<=r){
            newnode1=(struct node *)malloc(sizeof(struct node));
            if(num1*k%num2!=0)
            newnode1->data=num1*k;
            else
                newnode1->data=num1*(k+1);
            newnode1->next=NULL;
            ptr->next=newnode1;
            ptr=newnode1;
            i++;

            }
        }

    }
    return ptr->data;
}


int main()
{
    struct node *start=NULL;
    int num1,num2,r,q;
    printf("Enetr num1,num2,r\n");
    scanf("%d %d %d",&num1,&num2,&r);
    q=create(num1,num2,r,start);
    printf("\n%d",q);
    //dispaly(start);
    return 0;
}
