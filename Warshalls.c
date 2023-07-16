#include<stdio.h>
#include<stdlib.h>
int n,count;
void warshall(int graph[][n])
{
    for(int k=0;k<n;k++)//START 0 INDEXING ITSELF
    {
        for(int i=0;i<n;i++)
        {//NO COUNT HERE
            if(graph[i][k])
            for(int j=0;j<n;j++)
            {
                count++;
                if(graph[k][j])
                graph[i][j]=1;
            }
        }
    }
}
void main()
{
    FILE *fp1 = fopen("best.txt","w");
    FILE *fp2 = fopen("worst.txt","w");
    for(n=2;n<=20;n++)
    {
        int graph[n][n];
        //INITIALIZATION
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                graph[i][j]=0;
            }
        }
        //BEST CASE SPARSE
        for(int i=0;i<n;i++)
        {
               graph[i][i+1]=1;   
        }
        graph[n-1][1]=1;
        count=0;
        warshall(graph);
        fprintf(fp1,"%d\t\t%d\n",n,count);
        //WORST CASE DENSE
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j)
                graph[i][j]=0;
                else
                graph[i][j]=1;
            }
        }
        count=0;
        warshall(graph);
        fprintf(fp2,"%d\t\t%d\n",n,count);
    }
    fclose(fp1);
    fclose(fp2);
    //CORRECTNESS
    /*printf("Enter the Number of Vertices : ");
    scanf("%d",&n);
    int graph[n][n];
    printf("Enter the Adjacency Matrix\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        scanf("%d",&graph[i][j]);
    }
    warshall(graph);
    printf("The Transitive Closure of a Matrix is by Warshall is\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        printf("%d\t",graph[i][j]);
        printf("\n");
    }
    printf("The Count is : %d\n",count);*/
}
