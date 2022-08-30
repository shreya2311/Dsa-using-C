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
void push(char data1)
{   char data;
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
int isBalanced(char* str)
{
    int i;
    for(i=0;str[i];i++)
    {
        if(str[i]=='('||str[i]=='['||str[i]=='{')
            push(str[i]);
        else if(str[i]==')')
        {
            if(top==NULL||top->data!='(')
                return 0;
            pop();
        }
        else if(str[i]==']')
        {
            if(top==NULL || top->data!='[')
                return 0;
            pop();
        }
        else if(str[i]=='}')
        {
            if(top==NULL || top->data!='{')
                return 0;
            pop
            ();
        }
    }
    if(top==NULL)
        return 1;
    else
        return 0;
}
int main()
{
    int x;
    char st[20];
    printf("\nenter expression:");
    scanf("%s",&st);
    x=isBalanced(st);
    if(x==0)
        printf("\nnot balanced");
    else
        printf("\nbalanced");
}