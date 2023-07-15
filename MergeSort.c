#include <stdio.h>
#include<time.h>
#include <stdlib.h>
int count;
void Merge(int b[], int c[], int a[], int n)
{
    int i = 0, j = 0, k = 0, p = n / 2, q = n - n / 2;
    while (i < p && j < q)
    {
        count++;
        if (b[i] < c[j])
        {
            a[k] = b[i];
            i++;
        }
        else
        {
            a[k] = c[j];
            j++;
        }
        k++;
    }
    while (i < p)//no need of if (i==p) leads to different output
    {
        a[k] = b[i];
        i++;
        k++;
    }
    while (j < q)
    {
        a[k] = c[j];
        j++;
        k++;
    }
}

void MergeSort(int a[], int n)
{
    if (n == 1)
        return;
    int b[n / 2], c[n - n / 2];
    for (int i = 0; i < n / 2; i++)
        b[i] = a[i];
    for (int i = n / 2; i < n; i++)
        c[i - n / 2] = a[i];
    MergeSort(b, n / 2);
    MergeSort(c, n - n / 2);
    Merge(b, c, a, n);
}
void worst(int arr[],int beg,int end)
{
   if(beg<end)
    {
    int mid=(beg+end)/2;
    int i,j,k;
    int n1=(mid-beg)+1;
    int n2=end-mid;
    int a[n1],b[n2];
    for(i=0;i<n1;i++)
    a[i]=arr[(2*i)];
    for(j=0;j<n2;j++)
    b[j]=arr[(2*j)+1];
   worst(a,beg,mid);
   worst(b,mid+1,end);
  for(i=0;i<n1;i++)
   arr[i]=a[i];
   for(j=0;j<n2;j++)
   arr[j+i]=b[j];
 
  }

}
int main()
{
    FILE *fp1=fopen("best.txt","w");
    FILE *fp2=fopen("worst.txt","w");
    srand(time(NULL));
    for(int m=10;m<=1000;m=(m<100)?m+10:m+100)
    {
        count=0;
        int *a=(int *)malloc(sizeof(int)*m);
        for(int i=0;i<m;i++)
        *(a+i)=i+1;
        MergeSort(a,m);
        fprintf(fp1,"%d\t\t%d\n",m,count);
        count=0;
        for(int i=0;i<m;i++)
        *(a+i)=i+1;
        worst(a,0,m-1);
        MergeSort(a,m);
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
    printf("\nThe Elements are : ");
    for(int i = 0;i<n;i++)
    printf("%d\t",*(a+i));
    MergeSort(a,n);
    printf("\nThe Elements are : ");
    for(int i = 0;i<n;i++)
    printf("%d\t",*(a+i));
    printf("\nThe Count is : %d\n",count);*/
}
