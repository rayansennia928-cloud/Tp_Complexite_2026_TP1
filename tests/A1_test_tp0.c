#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10000

int estPremier(long long N)
{
    long long i;

    if (N < 2)
        return 0;

    for (i = 2; i < N; i++)
    {
        if (N % i == 0)
            return 0;
    }

    return 1;
}

int main()
{
    char *fichiers[] = {
        "Random100.txt",
        "Random1000.txt",
        "test-1.txt",
        "Test-2.txt",
        "Test-3.txt"
    };

    FILE *f, *csv;
    long long N;
    int k, resultat;
    clock_t debut, fin;
    double temps;
    char ligne[256];
    char *p, *finLecture;

    csv = fopen("resultats.csv", "w");

    if (csv == NULL)
    {
        printf("Erreur lors de la creation du CSV.\n");
        return 1;
    }

    fprintf(csv, "Fichier;Nombre;Resultat;Temps_secondes\n");

    for (k = 0; k < 5; k++)
    {
        printf("\nFichier : %s\n", fichiers[k]);

        f = fopen(fichiers[k], "r");

        if (f == NULL)
        {
            printf("Impossible d'ouvrir %s\n", fichiers[k]);
            continue;
        }

        while (fgets(ligne, sizeof(ligne), f) != NULL)
        {
            p = ligne;

            while (*p == ' ' || *p == '\t')
                p++;

            if (*p == '\n' || *p == '\0' || *p == '#')
                continue;

            N = strtoll(p, &finLecture, 10);

            if (p == finLecture)
                continue;

            debut = clock();
            resultat = estPremier(N);
            fin = clock();

            temps = (double)(fin - debut) / CLOCKS_PER_SEC;

            printf("N = %lld | %s | %.6f secondes\n",
                   N,
                   resultat ? "Premier" : "Non premier",
                   temps);

            fprintf(csv, "%s;%lld;%s;%.6f\n",
                    fichiers[k],
                    N,
                    resultat ? "Premier" : "Non premier",
                    temps);

            fflush(csv);
        }

        fclose(f);
    }

    fclose(csv);

    printf("\nTous les resultats sont enregistres dans resultats.csv\n");

    return 0;
}

