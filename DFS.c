#include<stdio.h>
#include<stdlib.h>
int graph[50][50],visited[50],path[50],d,isCyclic;
int count,dfscall;
void dfs(int n,int start,int parent)
{
    visited[start]=1;
    path[start]=1;
    count++;
    printf("%c---->",start+65);
    for(int i=0;i<n;i++)
    {
        if(d==1)
        {
            if(i!=parent && visited[i] && graph[start][i] && path[i])
            isCyclic=1; 
        }
        else
        {
            if(i!=parent && visited[i] && graph[start][i])
            isCyclic=1;
        }
        if(visited[i]==0 && graph[start][i])
        dfs(n,i,start);    
    }
    path[start]=0;
}
void main()
{
    //Generate Dense and Simply Connected Graph and append to file in a+ mode for different vertices
    //CORRECTNESS
    int n;
    printf("Enter the Number of Vertices : ");scanf("%d",&n);
    printf("Enter 1 if Graph is Directed Else 0 : ");scanf("%d",&d);
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
    dfs(n,0,-1);
    dfscall++;
    if(isCyclic)
        printf("Graph is Cyclic\n");
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
            dfs(n,start,-1);
            dfscall++;
            }
            start++;
        }
    }
    printf("Number Of Connected Componenets is %d\n",dfscall);
}