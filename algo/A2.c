#include <stdio.h>
#include <time.h>

int main()
{
    int N;
    int i;
    int premier;
    clock_t debut,fin;
    double temps;

    printf("Donner un nombre N : ");
    scanf("%d", &N);

    premier = 1;

    debut = clock();

    for (i = 2; i <= N / 2; i++)
    {
        if (N % i == 0)
        {
            premier = 0;
            break;
        }
    }

    fin = clock();
    temps= (double)(fin-debut)/CLOCKS_PER_SEC;

    if (premier == 1)
    {
        printf("%d est premier.\n", N);
    }
    else
    {
        printf("%d n'est pas premier.\n", N);
    }

    printf("Temps d'execution : %f secondes\n", temps);

    return 0;
}