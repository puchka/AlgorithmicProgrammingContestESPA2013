#include <stdio.h>
#include <stdlib.h>
#include "file.h"

#define SIZE_AFF 10
#define SIZE_NBAFF 10

void affiche(int *aff)
{
    int i;
    for (i=0;i<SIZE_AFF;i++)
    {
        printf("%d ", aff[i]);
    }
    printf("\n");
}

void affiche2(int *aff, int index)
{
    int i;
    for (i=0;i<index;i++)
    {
        printf("%d\n", aff[i]);
    }
    printf("\n");
}

int compare(int *a, int *b)
{
    if (*a<*b || *a==0)
        return 1;
    return -1;
}

void ajouter(int hi, int *aff)
{
    int i, j;
    qsort(aff, sizeof(int), sizeof(int), compare);
    //printf("\nqsort\n");
    //affiche(aff);
    for (i=0;i<SIZE_AFF;i++)
    {
        if (aff[i]==0)
        {
            aff[i] = hi;
            break;
        }
        else if (hi>=aff[i])
        {
            aff[i] = hi;
            for (j=i+1;j<SIZE_AFF;j++)
            {
                aff[j] = 0;
            }
            break;
        }
    }
    //affiche(aff);
}

int countAff(int *aff)
{
    int i, c = 0;
    for (i=0;i<SIZE_AFF;i++)
    {
        if (aff[i]!=0)
            c++;
    }
    //printf("\ncount\n");
    //printf("%d\n", c);
    return c;
}

int main()
{
    int nbQuery = 0;
    int i, hi, nbInput, index=0;
    char c;
    int aff[SIZE_AFF]={0};
    int nbaff[SIZE_NBAFF]={0};

    scanf("%d", &nbQuery);
    //while (getchar()!="\n");
    for (i=0;i<nbQuery;i++)
    {
        c = getchar();
        while (c!='C' && c!='Q')
            c = getchar();

        if (c=='Q')
        {
            //printf("boucle 1\n");
            nbaff[index]=countAff(aff);
            index++;
            //printf("%d\n", nbaff[index]);

        }
        //nbInput = scanf("% c %d", &typeq, &hi);
        //while (getchar()!="\n");


        else if (c=='C')
        {
            scanf("%d", &hi);
            //printf("\nhi : %d\n", hi);
            /*
            if (aff[0]==0)
            {
                aff[0] = hi;
                nbaff[0] = 1;
            }

            else
            {*/
                ajouter(hi, aff);
                //affiche(aff);
            //}
            //printf("boucle 2\n");
        }
    }
    printf("\n");
    affiche2(nbaff, index);
	getchar();
    return 0;
}
