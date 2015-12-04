/*Add a node to the circular linked list*/
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *create(struct node *start)
{
    struct node *newnode,*ptr;
    int num,n,i=0;
    printf("Enter Number of nodes\t");
    scanf("%d",&n);
    while(i<n)
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("Enter Node to insert");
        scanf("%d",&num);
        newnode->data=num;
        if(start==NULL)
        {
            newnode->next=newnode;
            start=newnode;
        }
        else
        {
            ptr=start;
            while(ptr->next!=start)
                ptr=ptr->next;
            ptr->next=newnode;
            newnode->next=start;
        }
        i++;

    }
    return start;

}
void display(struct node *start)
{
    struct node *ptr;
    ptr=start;
    while(ptr->next!=start){
        printf("\t%d",ptr->data);
        ptr=ptr->next;
    }
    printf("\t%d",ptr->data);
}

int main()
{
    struct node *start=NULL;
    start=create(start);
    //start=addnode(start);
    display(start);

    return 0;
}
