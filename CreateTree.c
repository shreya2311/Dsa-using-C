#include<stdio.h>
#include<stdlib.h>
                                     #we'll solve this by making a queue 
struct tree                          #we'll make a tree node and save its address to the queue
{                                    #as queue is Fifo it will help us to make a tree
    int data;                #when we search for left child we will push address into queue and while searching for right child we will pop that data address from queue
    struct tree* lchild;
    struct tree* rchild;
};
struct queue
{
    struct tree* data;
    struct queue* next;
};
struct queue* front=NULL;
struct queue* rear=NULL;
struct queue* nn(struct tree* data)
{
    struct queue* p=(struct queue*)malloc(sizeof(struct queue));
    p->data=data;
    p->next=NULL;
    return p;
}
void insert(struct tree* data)
{
    struct queue* ptr;
    ptr=nn(data);
    if(front==NULL){
        front=ptr;
        rear=ptr;
    }
    else
    {
        rear->next=ptr;
        rear=ptr;
    }
}
void display()
{
    int i;
    struct queue* front,* rear;
    struct queue* ptr;
    if(front==NULL)
        printf("\nqueue is empty");
    else
    {
        ptr=front;
        while(ptr!=NULL)
        {
            printf("\n%d",ptr->data);
            ptr=ptr->next;
        }
    }
}
struct tree* delete()
{
    struct queue* ptr;
    struct tree* data;
    data=front->data;
    ptr=front;
    front=front->next;
    free(ptr);
    ptr=NULL;
    return data;
}
struct tree* tnn(int data)
{
    struct tree* p;
    p=(struct tree*)malloc(sizeof(struct tree));
    p->data=data;
    p->lchild=NULL;
    p->rchild=NULL;
    return p;
}
struct tree* createTree()
{
    int data;
    struct tree* root,* ptr,* ptr1;
    printf("\nEnter root value:");
    scanf("%d",&data);
    root=tnn(data);
    insert(root);
    while(front!=NULL)
    {
        ptr=delete();
        printf("\nenter left child:");
        scanf("%d",&data);
        if(data!=-1)
        {
            ptr1=tnn(data);
            insert(ptr1);
            ptr->lchild=ptr1;
        }
    }
    printf("\nenter right child:");
    scanf("%d",&data);
    if(data!=-1)
    {
        ptr1=nn(data);
        insert(ptr1);
        ptr->rchild=ptr1;
    }
    return root;
}
void Preorder(struct tree* t)
{
    if(t!=NULL)
    {
        printf("\n%d",t->data);
        Preorder(t->lchild);
        Preorder(t->rchild);
    }
}
void Ineorder(struct tree* t)
{
    if(t!=NULL)
    {
        Inorder(t->lchild);
        printf("\n%d",t->data);
        Inorder(t->rchild);
    }
}
void Postorder(struct tree* t)
{
    if(t!=NULL)
    {
        Postorder(t->lchild);
        Postorder(t->rchild);
        printf("\n%d",t->data);
    }
}
int main()
{
    struct tree* root;
    root=createTree();
    Preorder(root);
}
