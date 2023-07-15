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
void selectionsort(int a[],int n)
{
    int minindex;
    for(int i=0;i<n;i++)
    {
        minindex = i;
        for(int j=i+1;j<n;j++)
        {
            count++;
            if(a[j]<a[minindex])
            minindex=j;
        }
        swap(&a[i],&a[minindex]);
    }
}
void main()
{
    FILE *fp=fopen("plot.txt","w");
    srand(time(NULL));
    for(int m=10;m<=1000;m=(m<100)?m+10:m+100)
    {
        count=0;
        int *a=(int *)malloc(sizeof(int)*m);
        for(int i=0;i<m;i++)
        *(a+i)=i+1;
        selectionsort(a,m);
        fprintf(fp,"%d\t\t%d\n",m,count);
        free(a);
    }
    fclose(fp);
    //CORRECTNESS
    /*printf("Enter the Number of Elements : ");int n;scanf("%d",&n);
    printf("Enter the Elements : ");
    int *a = (int *)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
    scanf("%d",(a+i));
    selectionsort(a,n);
    printf("The Elements are : ");
    for(int i = 0;i<n;i++)
    printf("%d\t",*(a+i));
    printf("\nThe Count is : %d\n",count);*/
}