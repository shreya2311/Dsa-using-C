#include<stdio.h>
#define size 5
int front=-1,rear=-1;
struct pqueue
{
    int data;
    int key;
};
struct pqueue queue[size];
void insert()
{
    int data,key,i;
    if(rear==size-1)
    {
        printf("\nqueue is full");
        return;
    }
    printf("\nenter data:");
    scanf("\n%d",&data);
    printf("\nenter key:");
    scanf("\n%d",&key);
    if(front==-1)
    {
        queue[0].data=data;
        queue[0].key=key;
        front=rear=0;
    }
    else
    {
        for(i=rear;i>=0&&queue[i].key>key;i--)
        {
            queue[i+1].data=queue[i].data;
            queue[i+1].key=queue[i].key;
        }
        queue[i+1].data=data;
        queue[i+1].key=key;
        rear++;
    }
}
void display()
{
    int i;
    if(front==-1)
        printf("\nqueue is empty");
    else
    {
        for(i=front;i<=rear;i++)
        {
            printf("\n%d-->%d",queue[i].data,queue[i].key);
        }
    }
}
void delete()
{
    int i;
    if(front==-1)
    {
        printf("\nqueue is empty");                  
        return;                                     
    }
    for(i=front;i<rear;i++)
        queue[i]=queue[i+1];
    rear--;
    if(rear==-1)
        front=-1;
}
int main()
{
    int ch;
    while(1)
    {
        printf("\n1.insert");
        printf("\n2.display");
        printf("\n3.delete");
        printf("\n4.exit");
        printf("\nenter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: insert();
                break;
            case 2: display();
                break;
            case 3: delete();
                break;
            case 4: return 0;
            default:printf("\ninvalid choice");
        }
    }
}