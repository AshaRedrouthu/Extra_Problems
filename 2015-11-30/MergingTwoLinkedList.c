/*Merge two linked list which are in sorted order*/
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
struct node *merge(struct node *start1,struct node *start2,struct node *result)
{
    if(start2==NULL)
        return start1;
    if(start1==NULL)
        return start2;
    if(start1==NULL&&start2==NULL)
        return NULL;
        struct node *ptr=NULL;
     if(start1->data < start2->data){
        result=start1;
        ptr=start1;
        start1 = start1->next;
     }
     else{
        result=start2;
        ptr=start2;
        start2 = start2->next;
    }
     while(start1!=NULL && start2!=NULL){
        if(start1->data < start2->data){
            ptr->next = start1;
            ptr=ptr->next;
            start1 = start1->next;
        }else{
            ptr->next = start2;
            ptr=ptr->next;
            start2 = start2->next;
        }
    }
    if(start2==NULL)
        ptr->next=start2;
    else
        ptr->next=start1;
    return result;

}

int main()
{
    struct node *start1=NULL,*start2=NULL,*result=NULL;
    start1 = create(start1);
    start2=create(start2);
    printf("\nList 1\n");
    display(start1);
    printf("\nList2\n");
    display(start2);
    result=merge(start1,start2,result);
    printf("\nMergedList\n");
    display(result);
    return 0;
}
