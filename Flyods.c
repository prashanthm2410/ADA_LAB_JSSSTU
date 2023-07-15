#include<stdio.h>
#include<stdlib.h>
int n,count;
int Min(int a,int b)
{
    return (a<b)?a:b;
}
void flyods(int graph[][n])
{
    int temp;
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            temp = graph[i][k];
            for(int j=0;j<n;j++)
            {
                count++;
                if(graph[i][j]>temp)
                graph[i][j]=Min(graph[i][j],temp+graph[k][j]);
            }
        }
    }
}
void main()
{
    FILE *fp = fopen("plot.txt","a+");
    //CORRECTNESS
    printf("Enter the Number of Vertices : ");
    scanf("%d",&n);
    int graph[n][n];
    printf("Enter the Adjacency Matrix\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        scanf("%d",&graph[i][j]);
    }
    flyods(graph);
    printf("The Shortes Path By Flyods is\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        printf("%d\t",graph[i][j]);
        printf("\n");
    }
    printf("The Count is : %d\n",count);
    fprintf(fp,"%d\t\t%d\n",n,count);
    fclose(fp);
}