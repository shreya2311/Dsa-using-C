#include<stdio.h>
#include<stdlib.h>
struct student
{
    int rollno;
    int age;
    struct student* next;
};
struct student* start=NULL;
struct student* nn(int rno,int ag)
{
    struct student* p=(struct student*)malloc(sizeof(struct student));
    p->rollno=rno;
    p->age=ag;
    p->next=NULL;
}
void add()
{
    int rollno,age;
    struct student* ptr,* p1;
    printf("\nenter age:");
    scanf("%d",&rollno);
    printf("/nenter age");
    scanf("%d",&age);
    p1=nn(rollno,age);
    if (start==NULL)
    {
        start=p1;
        start->next=start;
    }
    else
    {
        ptr=start;
        while(ptr->next!=start)
        {
            ptr=ptr->next;
        }
        ptr->next=start;
    }
}
void insert()
{
    int pos,n;
    struct student* ptr,* ptr1;
    printf("\n enter position");
    scanf("%d",&pos);
    if (pos==1)
    {
        ptr=start;
        while(ptr->next!=start)
        {
            ptr=ptr->next;
        }
        ptr->next=ptr1;
        ptr1->next=start;
        start=ptr1;
    }
}
void delete()
{
    struct student* ptr;
    ptr=start;
    while(ptr->next!=start)
    {
        ptr=ptr->next;
    }
    start=start->next;
    free(ptr->next);
    ptr->next=start;
}
