#include<stdio.h>
#include<stdlib.h>
int visited[50],graph[50][50],iscyclic,count,bfscall,graphcount;
void bfs(int n,int start)
{
   visited[start]=1;
   int queue[n],parent[n],parentnode,r=-1,f=-1;
   queue[++r]=start;
   parent[r]=-1;
   count++;
   while(r!=f)
   {
        start = queue[++f];
        parentnode=parent[f];
        printf("%c---->",start+65);
        for(int i=0;i<n;i++)
        {
            if(visited[i] && graph[start][i] && i!=parentnode)
            iscyclic=1;
            graphcount++;
            if(visited[i]==0 && graph[start][i])
            {
                queue[++r]=i;
                parent[r]=start;
                visited[i]=1;
                count++;
            }
        }
   }
}
void main()
{
    //WHILE RUNNING FOR PLOTING COMMENT OUT THE PRINTF INSIDE THE DFS FUNCTION
    /*FILE *fp=fopen("plot.txt","w");
    for(int m=2;m<=15;m++)
    {
        graphcount=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<m;j++)
            {
            if(i==j)
            graph[i][j]=0;
            else
            graph[i][j]=1;
            }
        visited[i]=0;
        }
        bfs(m,0);
        fprintf(fp,"%d\t\t%d\n",m,graphcount);
    }
    fclose(fp);*/
    printf("Enter the Number of vertices : ");int n,start;scanf("%d",&n);
    printf("Enter the Adjacency Matrix\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        scanf("%d",&graph[i][j]);
        visited[i]=0;
    }
    bfs(n,0);
    bfscall++;
    if(iscyclic)
    printf("\nGraph is Cyclic\n");
    else
    printf("\nGraph is Acyclic\n");
    if(count==n)
    printf("Graph is Connected\n");
    else
    {
        printf("Graph is NOT Connected\n");
        while(count!=n)
        {
            start=1;
            if(visited[start]==0)
            {
                printf("\n");
                bfs(n,start);
                bfscall++;
            }
            start++;
        }
    }
    printf("\nNumber of Conned Componenets is : %d\n",bfscall);
}
