#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int count;
void bubblesort(int a[],int n)
{
    int flag,temp;
    for(int i=0;i<n-1;i++)
    {
        flag = 0;
        for(int j = 0;j<n-i-1;j++)
        {
            count++;
            if(a[j]>a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                flag=1;//VVP
            }
        }
        if(flag==0)
        break;
    }
}
void main()
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
        bubblesort(a,m);
        fprintf(fp1,"%d\t\t%d\n",m,count);
        count=0;
        for(int i=0;i<m;i++)
        *(a+i)=m-i;
        bubblesort(a,m);
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
    bubblesort(a,n);
    printf("The Elements are : ");
    for(int i = 0;i<n;i++)
    printf("%d\t",*(a+i));
    printf("\nThe Count is : %d\n",count);*/
}