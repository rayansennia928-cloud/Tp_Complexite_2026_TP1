#include <math.h>

int A3(long long N)
{
    int premier = 1;
    long long i;

    if (N <= 1)
    {
        premier = 0;
    }
    else if (N == 2)
    {
        premier = 1;
    }
    else if (N % 2 == 0)
    {
        premier = 0;
    }
    else
    {
        // Complexite theorique :
        // Meilleur cas : O(1)
        // Pire cas : O(sqrt(N))

        for (i = 3; i <= sqrt((double)N); i += 2)
        {
            if (N % i == 0)
            {
                premier = 0;
                break;
            }
        }
    }

    return premier;
}
