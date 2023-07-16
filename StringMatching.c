#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int count,flag;
void StringMatching(char t[],char p[],int n,int m)
{
    int j;
    for(int i=0;i<=n-m;i++)
    {
        j=0;
        while(j<m && p[j]==t[i+j] )
        {
            count++;
            j++;
        }
        if(j==m)
        {
         flag=1;
        return ;
        }
    }
}
void main()
{
    FILE *fp1=fopen("best.txt","w");
    FILE *fp2=fopen("worst.txt","w");
    char *T =(char *)malloc(sizeof(char)*10000);
    for(int i=0;i<10000;i++)
    *(T+i)='a';
    for(int m=10;m<=10000;m=(m<1000)?m*10:m+1000)
    {
        count=0;
        char *P = (char *)malloc(sizeof(char)*m);
        for(int i=0;i<m;i++)
        *(P+i)='a';
        StringMatching(T,P,10000,m);
        fprintf(fp1,"%d\t\t%d\n",m,count);
        count=0;
        int i;
        for(i=0;i<m-1;i++)
        *(P+i)='a';
        *(P+i)='b';
        StringMatching(T,P,10000,m);
        fprintf(fp2,"%d\t\t%d\n",m,count);
        free(P);
    }
    free(T);
    fclose(fp1);
    fclose(fp2);
    //CORRECTNESS
    /*printf("Enter the Text : ");
    char text[100];
    scanf("%s",text);
    printf("Enter the Pattern : ");
    char pattern[100];
    scanf("%s",pattern);
    StringMatching(text,pattern,strlen(text),strlen(pattern));
    if(flag)
    printf("Pattern Found");
    else
    printf("Not matched");*/

}