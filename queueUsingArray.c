#include<stdio.h>
#define size 5
int queue[size];

int front=-1,rear=-1;

void insert()
{
    if(rear==size-1)
    {
        printf("\nqueue is full");
        return;
    }
    printf("\nenter data:");
    scanf("\n%d",&queue[++rear]);
    if(rear==0)
        front=0;
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
            printf("\n%d",queue[i]);
        }
    }
}
void delete()
{
    int i;
    if(front==-1)
    {
        printf("\nqueue is empty");                  /* this method is not that good as we shift every element one place forward */
        return;                                          /* so we use circular queue */
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