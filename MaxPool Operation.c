#include<stdio.h>


int main()
{
    int p, q, i, j;
    printf("input no. of rows ");
    scanf("%d",&p);
    printf("\ninput no. of columns ");
    scanf("%d",&q);
    int arr[p][q];
    printf("input entries of matrix ");
    for(i=0;i<p;i++)
    {
        for(j=0;j<q;j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    i=0,j=0;
    int maxPool[p/2][q/2];

    for(i=0;i<p;i+=2)
    {
        for(j=0;j<q;j+=2)
        {
            int max1 = (arr[i][j]>arr[i+1][j])?arr[i][j]:arr[i+1][j];
            int max2 = (arr[i][j+1]>arr[i+1][j+1])?arr[i][j+1]:arr[i+1][j+1];

            maxPool[i/2][j/2] = (max1>max2)?max1:max2;
        }
    }

    for(i=0;i<p/2;i++)
    {
        for(j=0;j<q/2;j++)
        {
            printf("%d ", maxPool[i][j]);
        }
        printf("\n");
    }
    return 0;
}
