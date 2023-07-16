#include<stdio.h>
#include<stdlib.h>
int graph[50][50],visited[50],path[50],isCyclic;
int count,bfscall;
void bfs(int n,int start)
{
    int queue[n],parent[n],parentnode,r=-1,f=-1;
    visited[start]=1;
    queue[++r]=start;
    parent[r]=-1;
    count++;
    while (r!=f)
    {
        start=queue[++f];
        parentnode=parent[f];
        printf("%c---->",start+65);
        for(int i=0;i<n;i++)
        {
            if(i!=parentnode && visited[i] && graph[start][i])
            isCyclic=1;
            if(visited[i]==0 && graph[start][i])
            {
                queue[++r]=i;
                parent[r]=start;//NOT parent node;
                visited[i]=1;
                count++;
            }

        }
    }
    
}
void main()
{
    //Generate Dense and Simply Connected Graph and append to file in a+ mode for different vertices
    //CORRECTNESS
    int n;
    printf("Enter the Number of Vertices : ");scanf("%d",&n);
    printf("Enter the Adjacency Matrix\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&graph[i][j]);
        }
        visited[i]=0;
        path[i]=0;
    }
    isCyclic=0;
    bfs(n,0);
    bfscall++;
    if(isCyclic)
        printf("\nGraph is Cyclic\n");
    else
        printf("Graph is Acyclic\n");
    if(count==n)
    printf("Graph is Connected\n");
    else
    {
        printf("Graph is NOT Connected\n");
        int start=1;
        while(count!=n)
        {
            if(visited[start]==0)
            {
            printf("\n");
            bfs(n,0);
            bfscall++;
            }
            start++;
        }
    }
    printf("Number Of Connected Componenets is %d\n",bfscall);
}