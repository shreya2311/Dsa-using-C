#include<stdio.h>
#include<stdlib.h>
struct student
{
    int rollno;
    int age;
    struct student* next;
    struct student* pre;
};
struct student* start=NULL;
struct student* nn(int rno, int ag)
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
    char ch;
    struct student* ptr,* p1;
    printf("\n enter rollno:");
    scanf("%d",&rollno);
    printf("\n enter age:");
    scanf("%d",&age);
    do
    {
        if (start==NULL)
        {
            start=p1;
        }
        else
        {
            ptr=start;
            while( ptr->next!=NULL)
            {
            ptr=ptr->next;
            }
        ptr->next=p1;
        p1->pre=ptr;
        printf("\n do you want to add more nodes? (y/n):");
        fflush(stdin);
        ch=getchar();
        }while(ch=='y');
    }
}
void fdisplay(struct student* ptr)
{
    if(start==NULL)
    {
        printf("\nlist is empty");
    }
    else
    {
        while(ptr!=NULL)
        {
            printf("\n%d-->%d",ptr->rollno,ptr->age);
            ptr=ptr->next;
        }
    }
}
void bdisplay(struct student* ptr)
{
    if(start==NULL)
    {
        printf("\n list is empty");
    }
    else
    {
        while(ptr!=NULL)
        {
            printf("\n%d-->%d",ptr->rollno,ptr->age);
            ptr=ptr->pre;
        }
    }
}
int main()
{
    add();
    add();
    add();
    fdisplay(start);
    bdisplay();
    return 0;
}