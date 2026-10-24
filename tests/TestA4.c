#include <stdio.h>
#include <time.h>
#include<math.h>
#include "A4.h"

int main(void){
int N;
int t[12]={1000003,2000003,4000037,8000009,16000057, 32000011,64000031,
128000003,256000001,512000009,1024000009,2048000011};
clock_t deb, fin; double tps;
for(int i=0;i<12;i++){
deb = clock();
if(A4(t[i])) printf("\n%d est premier",t[i]);
else printf("\n%d n'est pas premier",t[i]);
fin = clock();

tps = (double) (fin-deb)/ CLOCKS_PER_SEC;
printf("\nLe temps d'execution = %f",tps);
}
}