#include<stdio.h>
#include<stdlib.h>

struct dequeue
{
    int data;
    struct dequeue* next;
};
struct dequeue* front=NULL;
struct dequeue* rear=NULL;
struct dequeue* nn(int data)
{
    struct dequeue* p=(struct dequeue*)malloc(sizeof(struct dequeue));
    p->data=data;
    p->next=NULL;
    return p;
}
void insertleft()
{
    int data;
    struct dequeue* p1;
    printf("\nEnter data:");
    scanf("\n%d",&data);
    p1=nn(data);
    if(front==NULL){
        front=p1;
        rear=p1;
    }
    else
    {
        p1->next=front;
        front=p1;
    }
}
void insertright()
{
    int data;
    struct dequeue* p1,* ptr;
    printf("\nEnter data:");
    scanf("\n%d",&data);
    p1=nn(data);
    if(front==NULL){
        front=p1;
        rear=p1;
    }
    else{
        rear->next=p1;
        rear=p1;
    }
}
void deleteleft()
int main()
{
    int ch;
    while(1)
    {
        printf("\n1.I/P restricted dequeue");
        printf("\n2.O/P restricted dequeue");
        printf("\n3.exit");
        printf("\nenter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: switch(ch)
                {
                    case 1: insertleft();
                        break;
                    case 2: deleteleft();
                        break;
                    case 3: deleteright();
                        break;
                    case 4: exit();
                    default:printf("\ninvalid choice");
                }
            case 2: switch(ch)
                {
                    case 1: insertleft();
                        break;
                    case 2: insertright();
                        break;
                    case 3: deleteleft();
                        break;
                    case 4: exit();
                    default:printf("\ninvalid choice");
                }
            case 3: return 0;
            default:printf("\ninvalid choice");
        }
    }
}