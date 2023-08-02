#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int heapsize,n,src,count,removed[10]={0},cost[10][10],d[10]={0};
struct vertex
{
    int id,dist;
}heap[10];
typedef struct vertex ver;
void heapify(struct vertex arr[],int n,int i)
{
    while(1)
    {
        int largest=i,left=2*i+1,right=2*i+2;
        if(left<n && arr[left].dist<arr[largest].dist)
        largest=left;
        if(right<n && arr[right].dist<arr[largest].dist)
        largest=right;
        if(largest!=i)
        {
            struct vertex temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;
            i = largest;
        }
        else
        break;
    }
}
void HeapSort(struct vertex arr[],int n)
{
    for(int i=n/2-1;i>=0;i--)
    heapify(arr,n,i);
}
ver deleteheap(struct vertex heap[])
{
    struct vertex min = heap[0];
    heap[0] = heap[heapsize-1];
    heapsize--;
    heapify(heap,heapsize,0);
    return min;
}
void djistra()
{
    for(int i=0;i<n;i++)
    {
        heap[i].id=i;
        heap[i].dist=INT_MAX;
    }
    heap[src].dist=0;
    heapsize=n;
    HeapSort(heap,heapsize);
    while(count<n)
    {
        struct vertex min = deleteheap(heap);
        int u = min.id;
        removed[u]=1;
        count++;
        for(int i=0;i<n;i++)
        {
            if(!removed[i] && cost[u][i]!=INT_MAX)
            {
                if((d[u]+cost[u][i])<d[i])
                {
                    d[i]=(d[u]+cost[u][i]);
                    for(int o=0;o<heapsize;o++)
                    {
                        if(heap[o].id==i)
                        {
                            heap[o].dist=d[i];
                            break;
                        }
                    }
                    HeapSort(heap,heapsize);
                }
            }
        }
    }
}
void main()
{
    printf("Enter the Number of Vertices : ");scanf("%d",&n);
    printf("Enter the Cost Matrix\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
            cost[i][j]=INT_MAX;
        }
    }
    printf("Enter the Source Vertex : ");scanf("%d",&src);
    for(int i=0;i<n;i++)
    d[i]=INT_MAX;
    d[src]=0;
    djistra();
    printf("Shortes Path Starting from %d is\n",src);
    for(int i=0;i<n;i++)
    {
        if(src!=i)
        printf("%d---%d = %d\n",src,i,d[i]);
    }
}
