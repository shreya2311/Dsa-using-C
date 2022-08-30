#include<stdio.h>
#include<stdlib.h>
struct student
{
    int rollno;
    int age;
    struct student* next;
};
struct student* start=NULL;
struct student* nn(int rno, int ag)
{
    struct student* p=(struct student*)malloc(sizeof(struct student));
    p->rollno=rno;
    p->age=ag;
    p->next=NULL;
    return p;
}
void add()
{
    int rollno,age;
    struct student* p1,* ptr;
    printf("\n enter rollno:");
    scanf("%d", &rollno);
    printf("\n enter age:");
    scanf("%d", &age);
    p1=nn(rollno, age);
    if(start==NULL)
    {
        start=p1;
    }
    else
    {
        ptr=start;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=p1;
    }
}
void display()
{
    struct student* ptr;
    ptr=start;
    if(start==NULL)
    {
        printf("\n list is empty");
    }
    else
    {
        while(ptr!=NULL)
        {
            printf("\n%d-->%d", ptr->rollno, ptr->age);
            ptr=ptr->next;
        }
    }
}
int count(struct student* ptr)
{
    int c=0;
    while(ptr!=NULL)
    {
        c++;
        ptr=ptr->next;
    }
}
void insert()
{
    int pos,n,rollno,age,c;
    struct student* ptr,* ptr1;
    printf("\nenter position:");
    scanf("%d", &pos);
    n=count(start);
    if (pos<=0 || pos>n+1)
    {
        printf("\ninvalid position");
    }
    else
    {
        printf("\nenter rollno.:");
        scanf("%d", &rollno);
        printf("\nenter age:");
        scanf("%d", &age);
        ptr=nn(rollno,age);
        if (pos==1)
        {
            ptr->next=start;
            start=ptr;
        }
        else
        {
            ptr1=start;
            c=0;
            while(pos-2>c)
            {
                ptr1=ptr1->next;
                c++;
            }
            ptr->next=ptr1->next;
            ptr1->next=ptr;
        }
    }
}
int main()
{
    add();
    add();
    add();
    add();
    display();
    insert();
    return 0;
}