#include<stdio.h>
#include<stdlib.h>

struct stack1
{
    int data1;
    struct stack1* next1;
};
struct stack1* top1=NULL;
struct stack1* nn1(int data1)
{
    struct stack1* p=(struct stack1*)malloc(sizeof(struct stack1));
    p->data1=data1;
    p->next1=NULL;
    return p;
}
struct stack2
{
    int data2;
    struct stack2* next2;
};
struct stack2* top2=NULL;
struct stack2* nn2(int data2)
{
    struct stack2* ps=(struct stack2*)malloc(sizeof(struct stack2));
    ps->data2=data2;
    ps->next2=NULL;
    return ps;
}
void push1()
{   
    int data1;
    struct stack1* p1;
    printf("\nenter data:");
    scanf("%d",&data1);
    p1=nn1(data1);
    if(top1==NULL)
        top1=p1;
    else
    {
        p1->next1=top1;
        top1=p1;
    }
}
struct stack1* pop1()
{
    struct stack1* ptr1;
    if(top1==NULL)
    {
        printf("\nstack is empty");
    }
    else
    {
        ptr1=top1;
        top1=top1->next1;
        return ptr1;
    }
}
void push2()
{   
    struct stack2* ps,* ptr1;
    ps=ptr1;
    if(top2==NULL)
        top2=ps;
    else
    {
        ps->next2=top2;
        top2=ps;
    }
}
void display2()
{
    struct stack2* ptr2;
    ptr2=top2;
    while(ptr2!=NULL)
    {
        printf("\n%d",ptr2->data2);
        ptr2=ptr2->next2;
    }
}

void pop2()
{
    struct stack2* ptr2;
    if(top2==NULL)
    {
        printf("\nstack is empty");
        return;
    }
    ptr2=top2;
    top2=top2->next2;
    printf("\n%d",ptr2);
}
int main()
{
    int ch;
    while(1)
    {
        printf("\n1.PUSH in stack1");
        printf("\n2.PUSH in stack2");
        printf("\n3.POP from stack1");
        printf("\n4.POP from stack2");
        printf("\n5.DISPLAY stack2");
        printf("\n6.EXIT");
        printf("\nenter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: push1();
                break;
            case 2: push2();
                break;
            case 3: pop1();
                break;
            case 4: pop2();
                break;
            case 5: display2();
                break;
            case 6: return 0;
            default:printf("\ninvalid choice");
        }
    }
}