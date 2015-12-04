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
void display(struct node *start){
struct node *ptr;
ptr=start;
while(ptr->next!=NULL){
    printf("%d-->",ptr->data);
    ptr=ptr->next;
}
printf("%d\n",ptr->data);
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
struct node *arrange(struct node *start)
{
    struct node *preptr=start,*ptr=start,*s1=NULL,*s2=NULL;
    int count=1;
    if(start!=NULL)
    {
        ptr=preptr->next;
        while(count){
            if(ptr->data>preptr->data)
            {
                s2=preptr;
                preptr=ptr;
                ptr=ptr->next;
            }
            else{
                count=0;
                s1=reverse(preptr);
                s2->next=s1;
            }
        }
    }
    return start;

}

int main()
{
    struct node *start=NULL;
    start = create(start);
    display(start);
    start=arrange(start);
    display(start);

    return 0;
}
