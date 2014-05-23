#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_STRING_MAX 100

int palindrome(char *chaine, int a, int b)
{
    int i, result = 1;

    for (i=a;i<=b;i++,b--)
    {
        if (chaine[i]!=chaine[b])
        {
            result = 0;
            break;
        }
        if (i == b || i+1 == b)
            break;
    }
    return result;
}

int main()
{
    char *chaine[SIZE_STRING_MAX];
    scanf("%s", chaine);
    int i, j, max = 1, n = strlen(chaine);

    for (i = 2; i <= n; i++)
    {
        for (j = 0; i + j <= n ; j++)
        {
            if (palindrome(chaine, j, i + j - 1))
                if (i > max)
                    max = i;
        }
    }
    printf("%d\n", max);
    return 0;
}
