#include<stdio.h>
#include<stdlib.h>
int indegree[50],visited[50],queue[50],temp[50],graph[50][50],r=-1,f=0,n,count;
void ComputeIndegree()
{
    for (int i = 0; i < n; i++)
    {
        indegree[i] = 0;
        visited[i] = 0;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(graph[j][i]==1)
            indegree[i]++;
        }
        if(indegree[i]==0)
        {
            count++;
            queue[++r]=i;
            visited[i]=1;
        }
    }
}
void topological()
{
    int cnt=0;
    while(count!=0)
    {
        int source = queue[f++];
        count--;
        temp[cnt]=source;
        cnt++;
        for(int i=0;i<n;i++)
        {
            if(graph[source][i]==1)
            indegree[i]--;
        if(indegree[i]==0 && visited[i]==0)
        {
            count++;
            queue[++r]=i;
            visited[i]=1;
        }
        }
    }
    if(cnt!=n)
    printf("Cycle Exist\n");
    else
    {
         printf("\nThe Topological sorting is\n");
        for (int i = 0; i < n; i++)
            printf("%d---->\t", queue[i] + 1);
    }
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
    }
   ComputeIndegree();
   topological();
}