#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int count;
int LinearSearch(int a[],int n,int key)
{
    for(int i=0;i<n;i++)
    {
        count++;
        if(a[i]==key)
        {
            return i;
        }
    }
    return -1;
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
        int pos = LinearSearch(a,m,1);
        fprintf(fp1,"%d\t\t%d\n",m,count);
        count = 0;
        pos = LinearSearch(a,m,-1);
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
    int pos = LinearSearch(a,n,key);
    if(pos==-1)
    printf("Key Not Found \n");
    else
    printf("Key Found at : %d \n",pos+1);*/
}