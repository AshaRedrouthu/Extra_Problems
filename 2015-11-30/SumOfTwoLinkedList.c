// AddingTwoLlinkedList.cpp : Defines the entry point for the console application.
//
/*Write a program to add two linked list (Each node is represented by a digit ) (Note: Unequal Lengths can also be given )
Ex: Input 1->2->3->4 and 1->2->3->4
Output 2->4->6->8
*/
#include <stdio.h>
#include <malloc.h>
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
void display(struct node *list)
{
    if(list==NULL)
    {
        printf("\nLinkedList is Empty");
        return;
    }
    else{
            while(list->next!=NULL){
            printf("%d->",list->data);
            list=list->next;
        }
        printf("%d\n",list->data);
    }

}
struct node *addLinkedList(struct node *list1,struct node *list2)
{
    struct node *ptr1=NULL,*ptr2=NULL,*newnode,*end=NULL,*list3=NULL;
    if(list1!=NULL||list2!=NULL){
            ptr1=list1,ptr2=list2;
            while(ptr1!=NULL||ptr2!=NULL){
                newnode=(struct node*)malloc(sizeof(struct node));
                if(ptr1!=NULL&&ptr2!=NULL){
                    newnode->data=ptr1->data+ptr2->data;
                     ptr1=ptr1->next;
                     ptr2=ptr2->next;
                }
                else if(ptr1!=NULL){
                    newnode->data=ptr1->data;
                    ptr1=ptr1->next;
                }

                else{
                    newnode->data=ptr2->data;
                    ptr2=ptr2->next;
                }
                newnode->next=NULL;
                if(list3==NULL){
                    list3=newnode;
                    end=newnode;
                }
                else{
                    end->next=newnode;
                    end=newnode;
                }

            }

    }
    return list3;

}
int main()
{
	struct node *list1 = NULL, *list2 = NULL,*end1=NULL,*end2=NULL,*list3=NULL;
	list1 = create(list1);
	list2 = create(list2);
    display(list1);
    display(list2);
    list3=addLinkedList(list1,list2);
    display(list3);
    return 0;
}

