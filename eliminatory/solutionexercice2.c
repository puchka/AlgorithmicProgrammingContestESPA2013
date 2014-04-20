#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nbLettres, i, j, k;
    char lettres[300];
    scanf("%d", &nbLettres);
    scanf("%s", lettres);
    for (i=0;i<2*nbLettres-1;i++)
    {
        for (j=0;j<2*nbLettres-1;j++)
        {
            for (k=0;k<nbLettres;k++)
            {
                if (i==k || j==k || i==2*nbLettres-2-k || j==2*nbLettres-2-k)
                {
                    printf("%c", lettres[nbLettres-1-k]);
                    break;
                }
            }

        }
        printf("\n");
    }
    
	getchar();
    return 0;
}
