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
    struct student* ptr,* p1;
    printf("\n enter the rollno:");
    scanf("%d",&rollno);
    printf("\n enter age");
    scanf("%d",&age);
    p1=nn(rollno,age);
    if (start==NULL)
        start=p1;
    else
    {
        ptr=start;
        while(ptr!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=p1;
    }
}
int count()
{
    int c=0;
    struct student* ptr;
    ptr=start;
    while(ptr!=NULL)
    {
        c++;
        ptr=ptr->next;
    }
    return c;
}
void update()
{
    int age,rollno,pos,n;
    struct student* ptr;
    n=count();
    printf("\enter position to be updated");
    scanf("%d",&pos);
    
    if (pos<1 || pos>n)
    {
        printf("\ninvalid position");
    }
    else
    {
        ptr=start;
        int c=0;
        while(pos-1>c)
        {
            ptr=ptr->next;
            c++;
        }
        printf("\new rollno:");
        scanf("%d",&ptr->rollno);
        printf("\n enter new age:");
        scanf("%d",&ptr->age);
    }
}
void display()
{
    int rollno,age;
    struct student* ptr;
    while(ptr->next!=NULL)
    {
        printf("%d->%d",ptr->rollno,ptr->age);
        ptr=ptr->next;
    }
}
int main()
{
    add();
    add();
    add();
    add();
    update();
    display();
    return 0;
}