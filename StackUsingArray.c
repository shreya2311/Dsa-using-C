#include<stdio.h>
#define size 5

int stack[size];
int top=-1;
void push()
{
    int data;
    if(top==4)
    {
        printf("\n stack is full");
        return;
    }
    printf("\n enter data:");
    scanf("%d",&data);
    top++;
    stack[top]=data;
}
void pop()
{
    if(top==-1)
    {
        printf("\n stack is empty");
        return;
    }
    printf("\n enter element to be popped:%d",stack[top--]);
}
void display()
{
    if(top==-1)
    {
        printf("\n stack is empty");
        return;
    }
    else
    {
        int i;
        for(i=top;i>=0;i--)
            printf("\n%d",stack[i]);
    }
}
void peek()
{
    if(top==-1)
    {
        printf("\nstack is empty:");
        return;
    }
    printf("\n%d",stack[top]);
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