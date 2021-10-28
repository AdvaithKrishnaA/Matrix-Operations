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
    fp=fopen("input.txt","r"); // takes a file as input
    int krow, kcol, knum;
    fscanf(fp,"%d %d %d\n", &krow, &kcol, &knum); // first line of the input contains dimensions of the kernel matrix
    k **krnl = (k **)malloc(krow * sizeof(k *));
    for (int i = 0; i < krow; i++)
    {
        krnl[i] = (k *)malloc(kcol * sizeof(k));
    }
    for (int i = 0; i < krow; i++)
    {
        for (int j = 0; j < kcol; j++)
        {
            fscanf(fp,"%d %d %d\n", &krnl[i][j].kr, &krnl[i][j].kc, &krnl[i][j].kval); // subsequent lines consist of the element data in the following format: row< >column< >value
        }
    }
    int irow, icol, inum;
    fscanf(fp,"%d %d %d\n", &irow, &icol, &inum); // next line of the input contains dimensions of the image matrix
    im **img = (im **)malloc(irow * sizeof(im *));
    for (int i = 0; i < irow; i++)
    {
        img[i] = (im *)malloc(icol * sizeof(im));
    }
    for (int i = 0; i < irow; i++)
    {
        for (int j = 0; j < icol; j++)
        {
            fscanf(fp,"%d %d %d\n", &img[i][j].ir, &img[i][j].ic, &img[i][j].ival); // subsequent lines consist of the element data in the following format: row< >column< >value
        }
    }
    c cnvlt[irow][icol];
    int kcenterx = kcol / 2; // initialising center value
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
                        cnvlt[i][j].cval += img[ii][jj].ival * krnl[m][n].kval; // convoluted matrix
                    }
                }
            }
        }
    }
    for (int i = 0; i < irow; i++)
    {
        for (int j = 0; j < icol; j++)
        {
            printf("%d ", cnvlt[i][j].cval); // printing output
        }
        printf("\n");
    }
    fclose(fp);
}
