#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int data;
    struct stack* next;
};
struct stack* top=NULL;
struct stack* nn(int data)
{
    struct stack* p=(struct stack*)malloc(sizeof(struct stack));
    p->data=data;
    p->next=NULL;
    return p;
}
void push()
{   int data;
    struct stack* p1;
    printf("\nenter data:");
    scanf("%d",&data);
    p1=nn(data);
    if(top==NULL)
        top=p1;
    else
    {
        p1->next=top;
        top=p1;
    }
}
void display()
{
    struct stack* ptr;
    ptr=top;
    while(ptr!=NULL)
    {
        printf("\n%d",ptr->data);
        ptr=ptr->next;
    }
}
void pop()
{
    struct stack* ptr;
    if(top==NULL)
    {
        printf("\nstack is empty");
        return;
    }
    ptr=top;
    top=top->next;
    free(ptr);
    ptr=NULL;
}
void peek()
{   
    int data;
    if(top==NULL)
    {
        printf("\nStack is empty");
        return;
    }
    printf("\n%d",top->data);
}
int main()
{
    int ch;
    while(1)
    {
        printf("\n1.PUSH");
        printf("\n2.POP");
        printf("\n3.PEEk");
        printf("\n4.DISPLAY");
        printf("\n5.EXIT");
        printf("\nenter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: push();
                break;
            case 2: pop();
                break;
            case 3: peek();
                break;
            case 4: display();
                break;
            case 5: return 0;
            default:printf("\ninvalid choice");
        }
    }
}