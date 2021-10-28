#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    int kr;
    int kc;
    int kval;
} k;

typedef struct
{
    int ir;
    int ic;
    int ival;
} im;

typedef struct
{
    int cr;
    int cc;
    int cval;
} c;

int main()
{
    FILE *fp;
    fp=fopen("week15-ML1-input.txt","r");
    int krow, kcol, knum;
    fscanf(fp,"%d %d %d\n", &krow, &kcol, &knum);
    k **krnl = (k **)malloc(krow * sizeof(k *));
    for (int i = 0; i < krow; i++)
    {
        krnl[i] = (k *)malloc(kcol * sizeof(k));
    }
    for (int i = 0; i < krow; i++)
    {
        for (int j = 0; j < kcol; j++)
        {
            fscanf(fp,"%d %d %d\n", &krnl[i][j].kr, &krnl[i][j].kc, &krnl[i][j].kval);
        }
    }
    int irow, icol, inum;
    fscanf(fp,"%d %d %d\n", &irow, &icol, &inum);
    im **img = (im **)malloc(irow * sizeof(im *));
    for (int i = 0; i < irow; i++)
    {
        img[i] = (im *)malloc(icol * sizeof(im));
    }
    for (int i = 0; i < irow; i++)
    {
        for (int j = 0; j < icol; j++)
        {
            fscanf(fp,"%d %d %d\n", &img[i][j].ir, &img[i][j].ic, &img[i][j].ival);
        }
    }
    c cnvlt[irow][icol];
    int kcenterx = kcol / 2;
    int kcentery = krow / 2;
    for (int i = 0; i < irow; i++)
    {
        for (int j = 0; j < icol; j++)
        {
            cnvlt[i][j].cr = i;
            cnvlt[i][j].cc = j;
            cnvlt[i][j].cval=0;
            for (int m = 0; m < krow; m++)
            {
                for (int n = 0; n < kcol; n++)
                {
                    int ii = i + (m - kcentery);
                    int jj = j + (n - kcenterx);
                    if (ii >= 0 && ii < irow && jj >= 0 && jj < icol)
                    {
                        cnvlt[i][j].cval += img[ii][jj].ival * krnl[m][n].kval;
                    }
                }
            }
        }
    }
    for (int i = 0; i < irow; i++)
    {
        for (int j = 0; j < icol; j++)
        {
            printf("%d ", cnvlt[i][j].cval);
        }
        printf("\n");
    }
    fclose(fp);
}