void inorder(struct tree* t)
{
    while(top!=NULL || t!=NULL)
    {
        if(t!=NULL)
        {
            push(t);
            t=t->lchild;
        }
        else
        {
            t=pop();
            printf("%d\n",t->data);
            t=t->rchild;
        }
    }
}