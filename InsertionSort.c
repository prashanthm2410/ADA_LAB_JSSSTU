#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int count;
void insertionsort(int a[],int n)
{
    int j,temp;
    for(int i = 1;i<n;i++)
    {
        j=i-1;//VVP VVP
        temp = a[i];
        while(j>=0)
        {
            count++;
            if(a[j]>temp)
            {
                a[j+1]= a[j];
                j--;
            }
            else break;//VVP VVP
        }
        a[j+1] = temp;
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
        insertionsort(a,m);
        fprintf(fp1,"%d\t\t%d\n",m,count);
        count=0;
        for(int i=0;i<m;i++)
        *(a+i)=m-i;
        insertionsort(a,m);
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
    insertionsort(a,n);
    printf("The Elements are : ");
    for(int i = 0;i<n;i++)
    printf("%d\t",*(a+i));
    printf("\nThe Count is : %d\n",count);*/
}