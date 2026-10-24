
#include <stdio.h>
#include <time.h>
#include<math.h>
/*
int main() {
    long long N, i; 
    int premier = 1;
    //clock_t debut, fin; : stocke les valeurs de l'horloge du processeur au début et à la fin.
    clock_t debut, fin;
    double T;

    printf("Donner un nombre entier : ");  //1U
    scanf("%lld", &N);                     //1U
    //debut = clock(); : commence la mesure.
    debut = clock();                        //1U

    if (N ==0 || N==1 ||N %2==0) {   // 2U
        premier = 0;  //1U 
    } else {
        for (i = 2; i <sqrt(N) ; i++) {  //4U (nombre d'itération : sqrt(N)-1)
            if (N % i == 0) {    //2U
                premier = 0;     //1U
                break;    //1U
            }
        }
    }
    //fin = clock(); : termine la mesure.
    fin = clock();  //1U
    //CLOCKS_PER_SEC : permet de convertir la différence en secondes.
    T = (double)(fin - debut) / CLOCKS_PER_SEC;  //3U

    if (premier == 1) {  //1U
        printf("%lld est premier.\n", N); //1U
    } else {
        printf("%lld n'est pas premier.\n", N); //1U
    }

    printf("Temps d'execution : %.6f secondes\n", T);  //1U

    return 0;  //1U
    // la complexité temporelle au pire cas --> O(sqrt(N))
}*/

int A4(int N){
        int premier = 1, i;

   if (N ==0 || N==1 ||N %2==0) {   // 2U
        premier = 0;  //1U 
    } else {
        for (i = 2; i <sqrt(N) ; i++) {  //4U (nombre d'itération : sqrt(N)-1)
            if (N % i == 0) {    //2U
                premier = 0;     //1U
                break;    //1U
            }
        }
    }
}
