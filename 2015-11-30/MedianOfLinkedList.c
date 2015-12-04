/*Find median of a given linked list (Sorted Linked List)*/
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
int median(struct node *head)
{
    struct node *ptr=head,*preptr=head;
    if(head!=NULL){
    while(ptr!=NULL&&ptr->next!=NULL)
    {
        ptr=ptr->next->next;
        preptr=preptr->next;
    }
    return preptr->data;
    }
}

int main()
{
    struct node *start=NULL;
    int d;
    start = create(start);
    d=median(start);
    printf("%d",d);
    return 0;
}
