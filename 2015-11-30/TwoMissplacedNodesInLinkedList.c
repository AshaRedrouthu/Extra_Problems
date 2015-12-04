/*Sorted a linked list which is in ascending order but two numbers are changed ,i mean not in the usual order they need to be

Ex: 1->2->3->15->10->4->20; O/p:1-2-3-4-10-15-20
*/
#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *create(struct node *start){
	int data1,num,i=0;
	struct node *newnode,*end=NULL;
	printf("Enter Number of Nodes in a List\t");
	scanf("%d", &num);
	while (i < num){
		printf("Enter Data In a Node");
		scanf("%d", &data1);
		newnode = (struct node *)malloc(sizeof(struct node));
		newnode->data = data1;
		if (start == NULL){
			newnode->next = NULL;
			start = newnode;
			end = newnode;
		}
		else{
			newnode->next = NULL;
			end->next = newnode;
			end=newnode;
		}
		i++;
	}

	return start;
}
void display(struct node *start)
{
    if(start==NULL)
    {
        printf("\nLinkedList is Empty");
        return;
    }
    else{
            while(start->next!=NULL){
            printf("%d->",start->data);
            start=start->next;
        }
        printf("%d\n",start->data);
    }

}
struct node *oder(struct node *start)
{

    struct node *ptr=start,*prev=NULL,*n1=NULL,*n2=NULL;
    int count=0;
    if(start==NULL)
        return start;
    while(ptr->next!=NULL&&count!=2)
    {
        prev=ptr;
        ptr=ptr->next;
        if(ptr->data<prev->data)
        {
            count++;
            if(count==1)
                n1=prev;
            if(count==2)
                n2=ptr;
        }
    }
    if(count!=0)
    {
        n1->data=n1->data+n2->data;
        n2->data=n1->data-n2->data;
        n1->data=n1->data-n2->data;
    }
    return start;
}

int main()
{
    struct node *start=NULL;
    start = create(start);
    display(start);
    start=oder(start);
    display(start);
    return 0;
}
