#include<stdio.h>
#include<stdlib.h>

int v[100][100], val[100], wt[100], n, capacity, count;

int Max(int a, int b) {
    return (a > b) ? a : b;
}

int memoryfunction(int i, int j) {
    if (v[i][j] < 0) {
        if (j < wt[i])
            v[i][j] = memoryfunction(i - 1, j);
        else
            v[i][j] = Max(memoryfunction(i - 1, j), val[i] + memoryfunction(i - 1, j - wt[i]));
    }
    return v[i][j];
}

int knapsack(int n, int capacity) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= capacity; j++) {
            count++;
            v[i][j] = -1;
            if (i == 0 || j == 0)
                v[i][j] = 0;
        }
    }
    return memoryfunction(n, capacity);
}

void main() {
    FILE *fp = fopen("plot.txt", "a+");
    printf("Enter the Number of Items: ");
    scanf("%d", &n);
    printf("Enter the Sack Capacity: ");
    scanf("%d", &capacity);
    printf("Enter the Item Weight and their Price\n");
    printf("Weight\tPrice\n");
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &wt[i], &val[i]);
    }
    printf("The Worth of Sack is %d\n", knapsack(n, capacity));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= capacity; j++) {
            printf("%d\t", v[i][j]);
        }
        printf("\n");
    }
    for (int i = n; i > 0; i--) {
        if (v[i][capacity] != v[i - 1][capacity]) {
            printf("%d ", i);
            capacity = capacity - wt[i];
        }
    }
    printf("\nThe Count is %d\n", count);
    fprintf(fp, "%d\t\t%d\n", n, count);
    fclose(fp);
}
