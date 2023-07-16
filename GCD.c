#include<stdio.h>
#include<stdlib.h>
#define x 10
#define y 100
float euclid(int m,int n)
{
    float count=0;
    while(n)
    {
        count++;
        int temp = m%n;
        m=n;
        n=temp;
    }
    //printf("\n%d",m);
    return count;
    // m is ans
}
float consec(int m,int n)
{
    float count=0;
    int min=m;
    if(n<min)
    min=n;
    while(1)
    {
        count++;
        if(m %min ==0)
        {
            count++;
            if(n %min == 0)
            break;
            min--;//VVP
        }
        else
        min--;
    }
    //consec min is ans
    //printf("\n%d",min);
   return count;
}
float modified(int m,int n)
{
    int temp;
    float count = 0;
    while(n>0)
    {
        if(n>m)
        {
            temp =m;
            m = n;
            n = temp;
        }
        m=m-n;
        count++;
    }
    // modified m is ans
    //printf("\n%d",m);
    return count;
}
void analysis(int ch)
{
    int m, n, i, j, k;
    float count, maxcount, mincount;
    FILE *fp1, *fp2;
    switch (ch)
    {
    case 1:
        fp2 = fopen("e_b.txt", "w");
        fp1 = fopen("e_w.txt", "w");
        break;

    case 2:
        fp2 = fopen("c_b.txt", "w");
        fp1 = fopen("c_w.txt", "w");
        break;

    case 3:
        fp2 = fopen("m_b.txt", "w");
        fp1 = fopen("m_w.txt", "w");
        break;
    }
    for (i = x; i <= y; i += 10)
    {
        maxcount = 0;
        mincount = 10000;
        for (j = 2; j <= i; j++)
        {
            for (k = 2; k <= i; k++)
            {
                count = 0;
                m = j;
                n = k;

                switch (ch)
                {
                case 1:
                    count = euclid(m, n);
                    break;
                case 2:
                    count = consec(m, n);
                    break;
                case 3:
                    count = modified(m, n);
                    break;
                }
                if (count > maxcount)
                    maxcount = count;
                if (count < mincount)
                    mincount = count;
            }
        }

        fprintf(fp2, "%d %.2f\n", i, mincount);

        fprintf(fp1, "%d %.2f\n", i, maxcount);
    }
    fclose(fp1);
    fclose(fp2);
}

void main()
{
     int ch;
    for (ch = 1; ch <= 3; ch++)
    {
        analysis(ch);
    }
    //CORRECTNESS Change Arguments for different cases checking
    /*float p=euclid(99,33);
    p=consec(99,33);
    p=modified(99,33);*/

}