#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int count;
int BinarySearch(int a[],int low,int high,int key)
{
    if(low>high)
    return -1;
    int mid = (low+high)/2;
    count++;
    if(a[mid]==key)
    {
        return mid;
    }
    if(key<a[mid])
    return BinarySearch(a,low,mid-1,key);
    else
    return BinarySearch(a,mid+1,high,key);
}
void main()
{
    FILE *fp1=fopen("best.txt","w");
    FILE *fp2=fopen("worst.txt","w");
    srand(time(NULL));
    for (int m = 100; m <= 30000; m = (m <10000) ? m * 10 : m + 10000)
    {
        count=0;
        int *a=(int *)malloc(sizeof(int)*m);
        for(int i=0;i<m;i++)
        *(a+i)=i+1;
        int pos = BinarySearch(a,0,m-1,a[(m-1)/2]);
        fprintf(fp1,"%d\t\t%d\n",m,count);
        count = 0;
        pos = BinarySearch(a,0,m-1,-1);
        fprintf(fp2,"%d\t\t%d\n",m,count);
        free(a);
    }
    fclose(fp1);
    fclose(fp2);
    //CORRECTNESS
    /*printf("Enter the Number of Elements : ");int n;scanf("%d",&n);
    printf("Enter the Elements : ");
    int *a = (int *)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
    scanf("%d",(a+i));
    printf("Enter the Element to Search : ");int key;scanf("%d",&key);
    int pos = BinarySearch(a,0,n-1,key);
    if(pos==-1)
    printf("Key Not Found \n");
    else
    printf("Key Found at : %d \n",pos+1);
    printf("\nThe Count is %d\n",count);*/
}
