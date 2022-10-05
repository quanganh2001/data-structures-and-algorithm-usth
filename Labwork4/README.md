In this problem, we would like to implement the algorithm to calculate the digit sum of a given natural number that can be used in detecting errors in message transmission or data storage.

For example:

- N = 103509, the digit sum = 1 + 0 + 3 + 5 + 0 + 9 = 18.
- N = 9512, the digit sum = 9 + 5 + 1 + 2 = 17

# Exercise 1
- Write a pseudo-code to solve the above problem using Iteration.
```txt
Pseudo-code
sumDigit = 0
while N > 0
    sumDigit = sumDigit + N mod 10
N = N / 10
```
- Write a program from the pseudo-code and solve the Problem using Iteration.
```cpp
// Write a pseudo-code to solve the above problem using Recursion
// Pseudo-code
// sumDigit = 0
// while N > 0
    // sumDigit = sumDigit + N mod 10
// N = N / 10

// Write a program from the pseudo-code and solve the Problem using Iteration.
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number n: ";
    cin >> n;
    int sumDigit = 0;
    while (n > 0) {
        sumDigit += n % 10;
        n /= 10;
    }
    cout << "digit number is: " << sumDigit;
}

// Calculate the complexity. Justify your answer
// Complexity: log10(N)
```
Output:
```txt
Enter number n: 103509
digit number is: 18
```
- Calculate the complexity. Justify your answer.

Complexity: log10(N)

# Exercise 2
- Write a program to solve the Problem using **Recursion** (with Iteration if necessary).
- Calculate the complexity. Justify your answer.
```cpp
// Write a program to solve the Problem using Recursion (with Iteration if necessary).
#include <iostream>
using namespace std;

int sumDigit(int N) {
    if (N == 0) {
        return 0;
    }
    return N % 10 + sumDigit(N / 10);
}

int main() {
    int N;
    cout << "Enter number N: ";
    cin >> N;
    cout << "The digit number is: " << sumDigit(N);
    return 0;
}

// Calculate the complexity. Justify your answer
// Complexity: log10(N)
```
Output:
```txt
Enter number N: 10235
The digit number is: 11
```

# Exercise 3
Write a program in C/C++ to enter a natural number n and verify whether n is sphenic using **Recursion**. Calculate the complexity of the proposed algorithm

Note: A sphenic number is a product of $p*q*r$ where p, q and r are three distinct prime numbers. Example $30 = 2*3*5; 42 = 2*3*7; 66 = 2*3*11$
```cpp
// Write a program to enter a natural number n and find all sphenic numbers from 1 to N using Recursion (combined with iteration if necessary)

// Note: A sphenic number is a product of p*q*r where p, q and r are three distinct prime numbers. Example 30 = 2*3*5; 42 = 2*3*7; 66 = 2*3*11
#include <iostream>
#include <cstring>
using namespace std;

bool primes[1001]; // array will store all the prime numbers from 0 to 1000. Primes will be marked as true

// seive of eratosthenes to find all primes less than 1000
void primeSieve()
{
    // initialize all entries of 'primes' as true
    memset(primes, true, sizeof(primes));
    // traverse all numbers and mark their multiples as false
    // do not traverse false numbers
    for(int p = 2; p * p < 1001; p++)
    {
        if(primes[p])
        {
            for(int i = p * 2; i < 1001; i = i + p)
            {
                primes[i] = false;
            }
        }
    }
}

// function to return true if number is sphenic
bool isSphenic(int number)
{
    int arr1[8] = {0}; // array to store 8 divisors
    int count = 0; // track the number of divisors
    int j = 0;
    for(int i = 1; i <= number; i++)
    {
        if(number % i == 0 && count < 9)
        {
            count++;
            arr1[j++] = i;
        }
    }
    // if there are 8 divisors and the divisors are primes, the number is sphenic
    if(count == 8 && (primes[arr1[1]] && primes[arr1[2]] && primes[arr1[3]]))
        return true;
    return false;
}

// main function
int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    // generate all prime numbers
    primeSieve();
    cout << "The sphenic numbers between 1 and " << n << " are: \n";
    for(int i = 1; i <= n; i++)
    {
        if(isSphenic(i))
            cout << i << "\n";
    }
    return 0;
}
```
Output:
```txt
Enter n: 200
The sphenic numbers between 1 and 200 are:
30
70
105
154
165
182
195
```