#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>

char postfix[30]="100 20 - 15 5 + /";

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
void push(int data)
{
    struct stack* p1;
    p1=nn(data);
    if(top==NULL)
        top=p1;
    else
    {
        p1->next=top;
        top=p1;
    }
}
int pop()
{
    struct stack* ptr;
    int data=top->data;
    ptr=top;
    top=top->next;
    free(ptr);
    ptr=NULL;
    return data;
}
int peek()
{
    return top->data;
}
void PostfixEvaluation()
{
    int i,n,x,y;
    for(i=0;postfix[i];i++)
    {
        if(isdigit(postfix[i]))
        {
            n=0;
            while(isdigit(postfix[i]))
            {
                n=n*10+(postfix[i]-'0');
                i++;
            }
            push(n);
        }
        else if(postfix[i]==' ')
        {
            continue;
        }
        else
        {
            x=pop();
            y=pop();
            if(postfix[i]=='-')
                push(y-x);
            else if(postfix[i]=='+')
                push(y+x);
            else if(postfix[i]=='/')
                push(y/x);
            else if(postfix[i]=='*')
                push(y*x);
        }
    }
    printf("\n%d",pop());
}
int main()
{
    PostfixEvaluation();
}