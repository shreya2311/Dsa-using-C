#include<stdio.h>
#include<stdlib.h>
struct student
{
    int data;
    struct student* next;
};
struct student* nn(int data)
{
    struct student* p=(struct student*)malloc(sizeof(struct student));
    p->data=data;
    p->next=NULL;
    return p;
}
struct student* add(struct student* ptr,int data)
{
    struct student* p1;
    p1=nn(data);
    if(ptr!=NULL)
    {
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=p1;
    }
    return p1;
}
void display(struct student* ptr)
{
    if(ptr==NULL)
    {
        printf("\n list is empty");
    }
    else
    {
        while(ptr!=NULL)
        {
            printf("\n%d", ptr->data);
            ptr=ptr->next;
        }
    }
}
int main()
{
    struct student* start=NULL,*start1=NULL;
    start=add(start,100);
    add(start,200);
    add(start,300);
    add(start,400);
    add(start,500);
    add(start,600);
    start1=add(start1,10);
    add(start1,20);
    start1->next->next=start->next->next->next;
    display(start);
    printf("/n/n");
    display(start1);
}


