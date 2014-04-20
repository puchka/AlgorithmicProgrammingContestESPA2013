#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_CHAINE 100

int palindrome(char *chaine, int n)
{
    int i, result = 1;

    n = strlen(chaine)-1;
    for (i=0;i<n;i++)
    {
//        printf("i = %d\n", i);
//        printf("n-i = %d\n", n-i);
        if (chaine[i]!=chaine[n-i])
        {
            result = 0;
            break;
        }
        if (i==n-i || i+1 == n-i)
            break;


    }
    return result;
}

int main()
{
    char chaine[SIZE_CHAINE];
    scanf("%s", chaine);
    if (palindrome(chaine, strlen(chaine)))
        printf("%s est un palindrome.\n", chaine);
    else
        printf("%s n est pas un palindrome.\n", chaine);
	getchar();
    return 0;
}
