#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "A2.h"

#define MAX 10000

int main()
{
    char *fichiers[] = {
        "Random100.txt",
        "Random1000.txt",
        "test-1.txt",
        "test-2.txt",
        "Test-3.txt"
    };

    FILE *f, *resultats;
    long long N;
    int k, resultat;
    clock_t debut, fin;
    double temps;
    char ligne[256];
    char *p, *finLecture;

    resultats = fopen("resultats_A2.txt", "w");

    if (resultats == NULL)
    {
        printf("Erreur lors de la creation du fichier TXT.\n");
        return 1;
    }

    fprintf(resultats,
            "Fichier; Nombre; Resultat; Temps_secondes\n");

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

            resultat = A2(N);

            fin = clock();

            temps = (double)(fin - debut) / CLOCKS_PER_SEC;

            printf("N = %lld | %s | %.6f secondes\n",
                   N,
                   resultat ? "Premier" : "Non premier",
                   temps);

            fprintf(resultats,
                    "Fichier : %s | N = %lld | %s | %.6f secondes\n",
                    fichiers[k],
                    N,
                    resultat ? "Premier" : "Non premier",
                    temps);

            fflush(resultats);
        }

        fclose(f);
    }

    fclose(resultats);

    printf("\nTous les resultats sont enregistres dans resultats_A2.txt\n");

    return 0;
}
