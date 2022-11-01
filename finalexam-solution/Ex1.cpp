// given a natural N
// find a divisor d of N
// check if d is a prime, N = N/d (recursive)
#include <iostream>
using namespace std;

int isPrime(int a) {
    for (int i = 2; i < a/2; i++)
        if (a%i == 0)
            return 0;
}

int fact(int N, int i) {
    if (isPrime(N))
        printf("%d", N);
    else
        if ((N%i == 0) && isPrime(i)) {
            printf("%d*", i);
            fact(N/i, i);
        }
        else
            fact(N, i+1);
    return 0;
}

int main()
{
    int N = 84;
    printf("%d = ", N);
    fact(N, 2);

    return 0;
}