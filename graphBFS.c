void Bfs(int s,int visited[],int g[7][7])
{
    int x,i;
    printf("%d\n",s);
    visited[s]=1;
    insert(s);
    while(front)
    {
        x=delete();
        for(i=0;i<7;i++)
        {
            if(g[x][i]==1&&visited[i]==0)
            {
                printf("%d\n",i);
                visited[i]=1;
                insert(i);
            }

        }

    }
}
int main()
{
    int graph[7][7]={{0,1,1,1,0,0,0},
                     {1,0,1,0,0,0,0},
                     {1,1,0,1,1,0,0},
                     {1,0,1,0,1,0,0},
                     {0,0,1,1,0,1,1},
                     {0,0,0,0,1,0,0},
                     {0,0,0,0,1,0,0}};
    int visited[7]={0};
    Bfs(0,visited,graph);
}