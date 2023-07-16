#include<stdio.h>
#include<stdlib.h>
int visited[50],path[50],stack[50],top=-1,graph[50][50],flag,n;
void dfs(int n,int start,int parent)
{
    visited[start]=1;
    path[start]=1;
    for(int i=0;i<n;i++)
    {
        if(i!=parent && visited[i] && path[i] && graph[start][i])
        {
            flag=1;
            return;
        }
        if(visited[i]==0 && graph[start][i])
        dfs(n,i,start);
    }
    path[start]=0;
    stack[++top]=start;
}
void main()
{
    //a+ generate manually
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
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
            dfs(n, i,-1);
    }//Call in LOOP itself
    if(flag)
    printf("Cycle Exists No Solution\n");
    else
    {
        printf("\nTopological Order:\n");
        for(int i=top;i>=0;i--)
        printf("%c---->\t",stack[i]+65);
    }
}