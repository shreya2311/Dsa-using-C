#include<stdio.h>
#include<stdlib.h>

char infix[30]="x+y^z*p/q^r^s";
char postfix[30];                                                 /* R-L Associativity */

struct stack
{
    char data;
    struct stack* next;
};
struct stack* top=NULL;
struct stack* nn(char data)
{
    struct stack* p=(struct stack*)malloc(sizeof(struct stack));
    p->data=data;
    p->next=NULL;
    return p;
}
void push(char data)
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
char pop()
{
    struct stack* ptr;
    char data=top->data;
    ptr=top;
    top=top->next;
    free(ptr);
    ptr=NULL;
    return data;
}
char peek()
{
    return top->data;
}
int checkOperand(char ch)
{
    if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||(ch>='0'&&ch<='9'))
        return 1;
    return 0;
}
int Inpriority(char ch)
{
    if(ch=='+'||ch=='-')
        return 2;
    else if(ch=='*'||ch=='/')
        return 4;
    else if(ch=='^')
        return 6;
    else
        return -1;
}
int Outpriority(char ch)
{
    if(ch=='+'||ch=='-')
        return 1;
    else if(ch=='*'||ch=='/')
        return 3;
    else if(ch=='^')
        return 6;
    else 
        return -1;
}
void InfixToPostfix()
{
    int i,j=0;
    for(i=0;infix[i];i++)
    {
        if(checkOperand(infix[i]))
            postfix[j++]=infix[i]; 
        else if(infix[i]=='(')
            push(infix[i]);
        else if(infix[i]==')')
        {
            while(peek()!='(')
                postfix[j++]=pop();
            pop();
        }
        else{
            while(top!=NULL&&Outpriority(infix[i])<Inpriority(peek()))
            {
                postfix[j++]=pop();
            }
            push(infix[i]);
        }        
    }
    while(top!=NULL)
        postfix[j++]=pop();
}
int main()
{
    int i;
    InfixToPostfix();
    for(i=0;postfix[i];i++)
        printf("%c",postfix[i]);
}

