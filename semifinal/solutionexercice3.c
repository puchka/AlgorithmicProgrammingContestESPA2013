#include <stdio.h>
#include <stdlib.h>

#define NB_MAX 20

int estdejapresent(int *arrivee, int eleve)
{
    int i, result = 0;
    for (i=0;i<NB_MAX;i++)
    {
        if (arrivee[i]==0)
            break;
        if (eleve==arrivee[i])
        {
            result = 1;
            break;
        }

    }
    return result;
}

int elevepunis(int *arrivee, int nbeleves)
{
    int i, punis = 0;
    for (i=1;i<=nbeleves;i++)
    {
        if (!estdejapresent(arrivee, i))
        {
            punis = i;
            break;
        }


    }
    return punis;
}

int main()
{
    int arrivee[20]={0};
    int punis[20]={0};
//    arrivee[0] = 4;
//    arrivee[1] = 2;
//    printf("%d", elevepunis(arrivee, 4));
    int n, p, i, j, eleve;
    scanf("%d %d", &n, &p);
    for (i=0;i<p;i++)
    {

        scanf("%d", &eleve);
        arrivee[i] = eleve;
        if (elevepunis(arrivee, n)!=0)
        {
            punis[i] = elevepunis(arrivee, n);
        }
        else
        {
            if (i!=0)
                punis[i] = punis[i-1];
        }



    }
    printf("\n");
    for (i=0;i<NB_MAX;i++)
    {
        if (punis[i]==0)
            break;
        printf("%d\n", punis[i]);
    }
    if (punis[0]==0)
        printf("%d\n", -1);
    return 0;
}
