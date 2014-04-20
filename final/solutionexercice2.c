#include <stdio.h>
#include <stdlib.h>

#define SIZE_COL 100

void affiche(int *tab)
{
    int i;
    for (i = 0;i<SIZE_COL;i++)
    {
        printf("%d ", tab[i]);
    }
    printf("\n");
}

int pluslongcolonne(int *colonnes, int length, int col)
{
    int i, indexmaxcol = col;
    for (i = col;i<col+length;i++)
    {
        if (colonnes[i]>colonnes[indexmaxcol])
            indexmaxcol = i;
    }
    return indexmaxcol;
}

void horizontal(int *colonnes, int length, int col)
{
    int longestcol = colonnes[pluslongcolonne(colonnes, length, col)];
    int i;
    for (i=col;i<col+length;i++)
    {
        colonnes[i] = longestcol+1;
    }
}

void vertical(int *colonnes, int length, int col)
{
    colonnes[col]+= length;
}

int main()
{
    int colonnes[SIZE_COL] = {0};
    int n;                      // nombre de batons
    char o;
    int length, col;
//    colonnes[98] = 5;
//    colonnes[99] = 10;
//    printf("%d\n", pluslongcolonne(colonnes, 2, 98));
    scanf("%d", &n);
    while (n>0)
    {
        o=getchar();
        while (o!='H' && o!='V')
            o = getchar();
        scanf("%d %d", &length, &col);
        if (o=='H')
            horizontal(colonnes, length, col);
        else
            vertical(colonnes, length, col);
        //affiche(colonnes);
        n--;
    }
    //affiche(colonnes);
    printf("%d\n", colonnes[pluslongcolonne(colonnes, 100, 0)]);
    return 0;
}
