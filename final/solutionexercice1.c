#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_CH 500

int trouverdoublon(char *chaine)
{
    int i, n = strlen(chaine);
    char prec = chaine[0];
    for (i=1;i<n;i++)
    {
        if (prec==chaine[i])
            return i-1;           // position du premier doublon
        prec = chaine[i];
    }
    return -1;
}

void enleverdoublon(char *dest, char *chaine, int pos)
{
    int i = 0, j=0, n = strlen(chaine);

    while (i<n)
    {
        if (i==pos)
            j+=2;
        dest[i] = chaine[j];
        i++;
        j++;
    }
}

int main()
{
    char chaine[SIZE_CH], chaine2[SIZE_CH];
    scanf("%s", chaine);
    int test = trouverdoublon(chaine);
    while (test!=-1)
    {
        enleverdoublon(chaine2, chaine, test);
        strcpy(chaine, chaine2);
        test = trouverdoublon(chaine);
    }

    printf("%s", chaine2);
	getchar();
    return 0;
}
