
#include <math.h>

int A4(long long N)
{
    int premier = 1; //1u
    long long i; 

    if (N <= 1)
    {
        premier = 0; //1u
    } //2u
    else if (N == 2)
    {
        premier = 1; //1u
    }//2u
    else if (N % 2 == 0)
    {
        premier = 0; //1u
    }//2u
    else
    {
        for (i = 3; i <= sqrt((double)N); i += 2) 
        {//1u+(2u+2u)
            if (N % i == 0)
            {
                premier = 0; //1u
                break;
            }//3u
        }//4u+3u =7u
    }
    //nbr ite: (sqrt(n)-3+2 )/2 =(sqrt(n)-1 )/2
    // ((sqrt(n)-1 )/2)*7
    return premier;//1u
}//8+2+((sqrt(n)-1 )/2)*7)= 10+((sqrt(n)-1 )/2)*7 =O(sqrt(n)))
