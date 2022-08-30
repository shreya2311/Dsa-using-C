void preorder1(struct tree* t)
{
    while(top!=NULL||t!=NULL)
    {
        if(t!=NULL)
        
        {
            printf("%d\n",t->data);
            push(t);
            t=t->lchild;
        }
        else
        {
            t=pop()-rchild;
        }
    }
}
void preorder(struct tree* t)
{
    if(t!=NULL)
    {
        printf("%d\n",t->data);
        preorder(t->lchild);
        preorder(t->rchild);

    }
}