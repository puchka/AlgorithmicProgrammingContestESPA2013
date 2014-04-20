#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, nbdepl, direc, nmax, emax, smax, omax, x, y;
    nmax = emax = smax = omax = x = y = 0;
    scanf("%d", &n);
    while (n>0)
    {
        scanf("%d %d", &direc, &nbdepl);
        if (direc == 0)
        {
            y+=nbdepl;
            if (nmax<y)
                nmax = y;
        }
        else if (direc == 1)
        {
            x+=nbdepl;
            if (emax<x)
                emax = x;
        }
        else if (direc == 2)
        {
            y-=nbdepl;
            if (smax>y)
                smax = y;
        }
        else
        {
            x-=nbdepl;
            if (omax>x)
                omax = x;
        }

        n--;
    }
    nmax+=1;
    emax+=1;
    smax-=1;
    omax-=1;
    printf("%d", 2*(emax-omax)+2*(nmax-smax));
    getchar();
    return 0;
}
