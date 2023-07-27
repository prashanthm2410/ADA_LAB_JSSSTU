#include <stdio.h>
int cost[15][15], visited[15] = {0},n,num_edges=1,min,a,b,mincost=0;
void Min_Span_Tree()
{
    visited[0] = 1;
    while (num_edges< n) 
    {
        min = 1000;

        // In each cycle, find the minimum cost
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                if (cost[i][j] < min) 
                {
                    if (visited[i] != 0) 
                    {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }
    if (visited[b] == 0) 
        {
            printf("\n%d to %d  cost=%d", a, b, min);
            mincost += min;
            num_edges++;
        }
        visited[b] = 1;
        cost[a][b] = cost[b][a] = 1000;
    }
}
void  main() 
{
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter cost in form of adjacency matrix:\n");
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 1000;
        }
    }
    Min_Span_Tree();
    printf("\nminimum weight is %d\n",mincost);
}
