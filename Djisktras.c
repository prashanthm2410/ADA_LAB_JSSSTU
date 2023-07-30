#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
int n, i, j, src, cost[10][10], d[10] = {0}, removed[10] = {0}, count = 0;
int heapsize;
struct vertex
{
    int id;
    int dist;
}heap[10];
typedef  struct vertex ver;
// Min heap function declaration START
void heapify(struct vertex arr[], int n, int i)
{
    while(1)
    {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left].dist < arr[largest].dist)
        largest = left;
    if (right < n && arr[right].dist < arr[largest].dist)
        largest = right;
    if (largest != i)
    {
        struct vertex temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;
            i = largest;
    }
    else 
        {
            break;
        }
    }
}
void heapSort(struct vertex arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}
// Min heap function declaration end
// returns the min of the heap and heapifies the rest of the elements
ver deleteheap(ver heap[])
{
    ver min = heap[0];
    heap[0] = heap[heapsize - 1];
    heapsize = heapsize - 1;
    heapify(heap, heapsize, 0);
    return min;
}
void dijkstra()
{
    for (i = 0; i < n; i++)
    {
        heap[i].id = i;
        heap[i].dist = INT_MAX;
    }
    heap[src].dist = 0;
    heapsize = n;
    heapSort(heap, heapsize);
    while (count < n)
    {
        ver minvertex = deleteheap(heap);
        int u = minvertex.id;
        removed[u] = 1;
        count++;

        for (i = 0; i < n; i++)
        {
            if (!removed[i] && cost[u][i] != INT_MAX)
            {
                if ((d[u] + cost[u][i]) < d[i])
                {
                    d[i] = (d[u] + cost[u][i]);
                    for (int o = 0; o < heapsize; o++)
                    {
                        if (heap[o].id == i)
                        {
                            heap[o].dist = d[i];
                            break;
                        }
                    }
                    // to sort after editing
                    heapSort(heap, heapsize);
                }
            }
        }
    }
}
void main()
{
    printf("Enter the total number of vertices:");
    scanf("%d", &n);
    printf("Enter the cost matrix of the Graph\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = INT_MAX;
        }
    }
    // Initialise the source vertex distance to 0 and rest all to infinity(INT_MAX)
    printf("Enter the source vertex:");
    scanf("%d", &src);
    for (i = 0; i < n; i++)
    {
        d[i] = INT_MAX;
    }
    d[src] = 0;
    dijkstra();
    printf("Shortest path id %d is:\n", src);
    for (i = 0; i < n; i++)
    {
        if (src != i)
            printf("%d -> %d = %d\n", src, i, d[i]);
    }
}
