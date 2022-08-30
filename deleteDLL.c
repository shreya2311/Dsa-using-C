#include<stdio.h>
#include<stdlib.h>
struct student
{
    int rollno;
    int age;
    struct student* next;
    struct student* pre;
};
struct student* start==NULL;
void add();
struct student* nn(int,int);
int count(start);
void delete();
void display();
struct student* nn(int rno,int ag)
{
    struct student* p=(struct student*)malloc(sizeof(struct student));
    p->rollno=rno;
    p->age=ag;
    p->next=NULL;
    p->pre=NULL;
    return p;
}
void add()
{
    int rollno,age;
    struct student* ptr,* p1;
    printf("enter rollno:");
    scanf("%d",&rollno);
    printf("enter age:");
    scanf("%d",&age);
    p1=nn(rollno,age);
    if (start==NULL)
        start=p1;
    else
    {
        ptr=start;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=p1;
        p1->pre=ptr;
    }
}
int count()
{
    struct student* ptr;
    int c=0;
    while(ptr!=NULL)
    {
        c++;
        ptr=ptr->next;
    }
    return c;
}
void delete()
{
    int pos,n,c;
    struct student* ptr,* ptr1;
    ptr=start;
    printf("enter position:");
    scanf("%d",&pos);
    n=count(start);
    if (pos<1 || pos>n)
        printf("position is invalid");
    else
    {
        if (pos==1)
        {
            ptr=start;
            start=start->next;
            free(ptr);
            if(start!=NULL)
                start->pre=NULL;
        }
        else
        {
            c=0;
            ptr=start;
            while(pos-1>c)
            {
                ptr=ptr->next;
                c++;
            }
            ptr->pre->next=ptr->next;
            if(ptr->next!=NULL)
                ptr->next->pre=ptr->pre;
            free(ptr);
            ptr=NULL;
        }
    }
}
void display()
{
    int rollno,age;
    struct student* ptr;
    ptr=start;
    while(ptr!=NULL)
    {
        printf("%d-->%d",ptr->rollno,ptr->age);
        ptr=ptr->next;
    }
}
int main()
{
    add();
    add();
    add();
    add();
    count(start);
    delete();
    display();
}