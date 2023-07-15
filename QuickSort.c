#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int count;
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int a[],int l,int r)
{
    int p = a[l],i=l+1,j=r;
    while(i<=j) //= important
    {
        while(i<=r)
        {
            count++;
            if(a[i]<p)
            i++;
            else 
            break;
        }
        while(j>=l)
        {
            count++;
            if(a[j]>p)
            j--;
            else 
            break;
        }
        if(i<=j)// = impoertant
        {
        swap(&a[i],&a[j]);
            i++;
            j--;
        }
    }
    swap(&a[l],&a[j]);
    return j;
}
void QuickSort(int a[],int l,int r)
{
    if(l==r)
    return;
    else if(l<r)
    {
        int s = partition(a,l,r);
        QuickSort(a,l,s-1);
        QuickSort(a,s+1,r);
    }
}
void main()
{
    FILE *fp1=fopen("best.txt","w");
    FILE *fp2=fopen("average.txt","w");
    FILE *fp3=fopen("worst.txt","w");
    srand(time(NULL));
    for(int m=10;m<=1000;m=(m<100)?m+10:m+100)
    {
        count=0;
        int *a=(int *)malloc(sizeof(int)*m);
        for(int i=0;i<m;i++)
        *(a+i)=i+1;
        QuickSort(a,0,m-1);
        fprintf(fp1,"%d\t\t%d\n",m,count);
        count=0;
        for(int i=0;i<m;i++)
        *(a+i)=i+1;
        QuickSort(a,0,m-1);
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
    QuickSort(a,0,n-1);
    printf("The Elements are : ");
    for(int i = 0;i<n;i++)
    printf("%d\t",*(a+i));
    printf("\nThe Count is : %d\n",count);*/

}