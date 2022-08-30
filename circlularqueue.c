#include<stdio.h>
#define size 5
int queue[size];

int front=-1,rear=-1;

void insert()
{
    if((rear+1)%size==front)
    {
        printf("\nqueue is full");
        return;                                                            /*using Array*/
    }
    if(front==-1)
        front=rear=0;
    else if(rear==size-1)
        rear=0;
    else
        rear++;
    printf("\nenter data:");
    scanf("%d",&queue[rear]);
}
void display()
{
    int i;
    if(front==-1){
        printf("\nqueue is empty");
        return;
    }
    if(rear>=front)
    {
        for(i=front;i<=rear;i++)
            printf("\n%d",queue[i]);
    }
    else
    {
        for(i=front;i<=size-1;i++)
            printf("\n%d",queue[i]);
        for(i=0;i<=rear;i++)
            printf("\n%d",queue[i]);
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
    if(front==rear)
        front=rear=-1;
    else if(front=size-1)
        front=0;
    else
        front++;
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