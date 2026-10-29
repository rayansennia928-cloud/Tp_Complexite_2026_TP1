#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "A3.h"

int main(void)
{
    char *fichiers[] = {
        "donnees/Random100.txt",
        "donnees/Random1000.txt",
        "donnees/test-1.txt",
        "donnees/Test-2.txt",
        "donnees/Test-3.txt"
    };

    int nbFichiers = sizeof(fichiers) / sizeof(fichiers[0]);

    FILE *f, *csv;
    long long N;
    int k, resultat;
    clock_t debut, fin;
    double temps;
    char ligne[256];
    char *p, *finLecture;

    csv = fopen("resultats_A3.csv", "w");

    if (csv == NULL)
    {
        printf("Erreur lors de la creation du CSV.\n");
        return 1;
    }

    fprintf(csv, "Fichier;Nombre;Resultat;Temps_secondes\n");

    for (k = 0; k < nbFichiers; k++)
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
            resultat = A3(N);
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
        }

        fclose(f);
    }

    fclose(csv);

    printf("\nTous les resultats sont enregistres dans resultats_A3.csv\n");

    return 0;
}