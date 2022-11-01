# Problem
In this problem, we would like to perform a prime factorization of a given natural number N:

**N = 120 = 2 * 2 * 2 * 3 * 5;**

**N = 84 = 2 * 2 * 3 * 7;**

# Question 1
- Write a pseudo-code to implement the factorization using **Recursion** (combined with iteration if necessary).
- Implement the proposed pseudo-code using C/C++.
- Calculate the complexity of your program (Best scenario, Worst scenario, Average). Justify your answer.

**Solution**

Calculate the complexity of your program: O(n)

- the function calls itself log(n) times, in each call, O(n) => O(nlog(n))
- if N is prime => one iteration (best case)
- N is the product of two primes numbers (worst scenario)

```cpp
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
```

When I input the number is 84, the output is $84 = 2*2*3*7$


# Question 2
We would like to improve the factorization by using Divide and Conquer strategy and Binary recursion:

Step 1: Given a natural number N;

Step 2: Find two biggest divisors of N denoted by d1, d2;

Step 3: If a divisor d1 or d2 is not a prime, then call step 1 for d1 or d2, respectively; else continue;

Step 4: If d1 and d2 are both prime then exit;

- Implement the proposed pseudo-code using C/C++
- Calculate the complexity of this algorithm. Justify your answer.

**Solution**

Exercise 2 Complexity of this algorithm: O(log(n) or sqrt(n)) << O(n) where log(n) ~ sqrt(n)

In the main functions, fact2 is called => fact2 calls itself log(n) times, for each times, we need O(n) to check primes => finally, O(nlog(n))

```cpp
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
    int N = 2000;
    printf("%d = ", N);

    fact2(N);

    return 0;
}
```

When I input the number is 2000, the output is $2000 = 5*2*4*5*2*5$, similarity for the number is 3240, the output is: $3240 = 2*3*3*3*2*3*2*5$