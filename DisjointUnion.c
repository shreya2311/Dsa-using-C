void union(int x, int y)
{
    if (set[x]>set[y])
    {
        set[y]=set[x]+set[y];
        set[x]=y;
    }
    else
    {
        set[x]=set[x]+set[y];
        set[y]=x;
    }
}