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
struct node *reverse(struct node *start)
{
    struct node *root=NULL;
    if(start->next!=NULL)
    {
        root=reverse(start->next);
        start->next->next=start;
        start->next=NULL;
        return root;
    }
    else{
        return start;
    }
}
void display(struct node *start){
struct node *ptr;
ptr=start;
while(ptr->next!=NULL){
    printf("%d-->",ptr->data);
    ptr=ptr->next;
}
printf("%d\n",ptr->data);
}
int main()
{
    struct node *start=NULL,*p1=NULL;
    start = create(start);
    printf("\nGiven List\n");
    display(start);
    start=reverse(start);
    printf("\nReversed Linked List\n");
    display(start);
    return 0;
}
