#include <stdio.h>
#include <stdlib.h>

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
	
}

int countAff(int *aff)
{
    int i, c = 0;
    for (i=0;i<SIZE_AFF;i++)
    {
        if (aff[i]!=0)
            c++;
    }
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
    for (i=0;i<nbQuery;i++)
    {
        c = getchar();
        while (c!='C' && c!='Q')
            c = getchar();

        if (c=='Q')
        {
            nbaff[index]=countAff(aff);
            index++;
        }
        else if (c=='C')
        {
            scanf("%d", &hi);
			ajouter(hi, aff);
        }
    }
    printf("\n");
    affiche2(nbaff, index);
	getchar();
    return 0;
}
