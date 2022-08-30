#include<stdio.h>
#include<stdlib.h>

struct queue
{
    int data;
    struct queue* next;
};
struct queue* front=NULL;
struct queue* rear=NULL;
struct queue* nn(int data)
{
    struct queue* p=(struct queue*)malloc(sizeof(struct queue));
    p->data=data;
    p->next=NULL;
    return p;
}
void insert()
{
    int data;
    struct queue* front,* rear;
    struct queue* p1;
    printf("\nEnter data:");
    scanf("\n%d",&data);
    p1=nn(data);
    if(front==NULL){
        front=p1;
        rear=p1;
    }
    else
    {
        rear->next=p1;
        rear=p1;
    
    }
}
void display()
{
    int i;
    struct queue* front,* rear;
    struct queue* ptr;
    if(front==NULL)
        printf("\nqueue is empty");
    else
    {
        ptr=front;
        while(ptr!=NULL)
        {
            printf("\n%d",ptr->data);
            ptr=ptr->next;
        }
    }
}
void delete()
{
    struct queue* ptr,* front;
    int i;
    if(front==NULL)
        printf("\nqueue is empty");
    else
    {
        ptr=front;
        front=front->next;
        free(ptr);
        ptr=NULL;
    }
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