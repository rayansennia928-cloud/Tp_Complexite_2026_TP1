#include <stdio.h>
#include <time.h>
#include "A1.h"

int A1(long long N)
{
long long i;
int premier = 1;


if (N < 2) {
    premier = 0;
} else {
    for (i = 2; i < N; i++) {
        if (N % i == 0) {
            premier = 0;
            break;
        }
    }
}

return premier;


}
