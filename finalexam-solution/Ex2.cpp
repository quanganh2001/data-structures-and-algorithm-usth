// given a natural N
// find a divisor d of N
// check if d is a prime, N = N/d (recursive)
#include <iostream>
#include <math.h>
using namespace std;

/* Question 1 Complexity: O(n)*/
int isPrime(int a) {
    for (int i = 2; i < a/2; i++)
        if (a%i == 0)
            return 0;
}

// the function calls itself log(n) times, in each call, O(n) => O(nlog(n))
// if N is prime => one iteration (best case)
// N is the product of two primes numbers (worst scenario)
int fact(int N, int i) {
    if (isPrime(N)) // O(n) * log(n) = O(nlog(n))
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

// Exercise 2 Complexity O(log(n) or sqrt(n)) << O(n) where log(n) ~ sqrt(n)
int findBiggestDiv(int N) {
    int d1 = sqrt(N);
    while ((N % d1 != 0) && (d1 > 1)) {
        d1 = d1 - 1;
    }
    return d1;
}

// in the main functions, fact2 is called => fact2 calls itself log(n) times, for each times
// we need O(n) to check primes => finally, O(nlog(n))
int fact2(int N) {
    if (isPrime(N)) // O(n)
        printf("%d*", N);
    else {
        int d1 = findBiggestDiv(N);
        int d2 = N/d1;
        fact2(d1);
        fact2(d2);
    }

    return 0;
}

// main function
int main()
{
    int N = 3240;
    printf("%d = ", N);

    fact2(N);

    return 0;
}