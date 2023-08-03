#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int count,count1;
void Heap_Sort(int H[], int n) {
    for (int i = n / 2; i >= 1; i--) {
        int pi = i, pv = H[i];
        int ci;
        bool Heap = false;
        while (!Heap && 2 * pi <= n) {
            ci = 2 * pi;
            count++; // for leaf comparisons
            if (ci < n) {
                if (H[ci + 1] > H[ci])
                    ci = ci + 1;
            }
            count++; // for leaf and its respective parent comparison
            if (pv > H[ci])
                Heap = true;
            else {
                H[pi] = H[ci];
                pi = ci;
            }
        }
        H[pi] = pv;
    }
}
/*construction best case =n-1 worst 2(n-log(n+1))
deletion 2(n-1)log(n-1) both best and worst*/
void Heapify(int H[], int n, int i) {
    while (true) {
        int largest = i;
        int left = 2 * i;
        int right = 2 * i + 1;
        
        if (left <= n)
        {
        count1++;
        if(H[left] > H[largest])
            largest = left;
           }
        //count1++;
        if (right <= n)
        {
        count1++;
        if(H[right] > H[largest])
            largest = right;
}
        if (largest != i) {
            //count1++;
            int temp = H[i];
            H[i] = H[largest];
            H[largest] = temp;
            i = largest;
        } else {
            break;
        }
    }
}

void delete(int H[], int *n) {
    if (*n == 0) {
        printf("Heap is empty.\n");
        return;
    }

    H[1] = H[*n];
    (*n)--;
    Heapify(H, *n, 1);
}

void display(int H[], int n) {
    for (int i = 1; i <= n; ++i)
        printf("%d\t", H[i]);
    printf("\n");
}

int main()
{
    /*FILE *fp1=fopen("best.txt","w");
    FILE *fp2=fopen("worst.txt","w");
    if(fp1==NULL || fp2==NULL)
    {
        printf("ERROR OPENING FILE\n");
        return 1;
    }
    for(int m=100;m<=10000;m=(m<1000)?m+100:m+1000)
    {
        count=0;count1=0;
        int *a=(int *)malloc(sizeof(int)*m);
        for(int i=0;i<m;i++)
        *(a+i)=m-i;//Best Case Decreasing Order
        Heap_Sort(a,m);int n=m;
       for(int i=m;i>=1;i--)
       delete(a,&n); fprintf(fp1,"%d\t\t%d\n",m,count+count1);
        for(int i=0;i<m;i++)
        *(a+i)=i+1;//Worst Case Decreasing Order
        count=0;count1=0;
        Heap_Sort(a,m);n=m;
       for(int i=m;i>=1;i--)
       delete(a,&n); fprintf(fp2,"%d\t\t%d\n",m,count+count1);
        free(a);
    }
    fclose(fp1);
    fclose(fp2);*/
    //CORRECTNESS
   printf("Enter the Number of Elements : ");int n;scanf("%d",&n);
   int *a=(int *)malloc(sizeof(int)*n);
   printf("Enter the Elements : ");
   for(int i=1;i<=n;i++)
   scanf("%d",(a+i));
   Heap_Sort(a,n);
   display(a,n);
   printf("Deleting elements in decreasing order\n");
    for (int i = n; i >= 1; i--) 
    {
        delete(a, &n);
        display(a, n);
    }
}
