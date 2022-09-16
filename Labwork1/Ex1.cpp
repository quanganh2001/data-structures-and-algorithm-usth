// Write a pseudo-code then implement a program in C/C++ to enter a natural number n and verify whether n is sphenic. Calculate the complexity of your program.
// Input : 30
// Output : Yes
// Explanation : 30 is the smallest Sphenic number, 
//            30 = 2 × 3 × 5 
//            the product of the smallest three primes

// Input : 60
// Output : No
// Explanation : 60 = 22 x 3 x 5
//               has exactly 3 prime factors but
//               is not a sphenic number

// pseudocode
// BEGIN
// Get N
// for(i = 2; i <= temp; i = i + 1)
//     while(N % i = 0)
//         count++
//         N /= i
//     if (count >= 2)
//         print false
//     if (count == 1)
//         num++
// if function different equal 1 print num++, number equal to 3 print true then return false

// Note: A sphenic number is a product of p*q*r where p, q and r are three distinct prime numbers. Example 30 = 2 * 3 * 5; 42 = 2 * 3 * 7; 66 = 2 * 3 * 11
#include <iostream>
#include <math.h>
using namespace std;

bool isSphenic(int N) {
    int num = 0;
    int temp = sqrt(N);
    for (int i = 2; i <= temp; i++) {
        int count = 0;
        while (N % i == 0) {
            count++;
            N /= i;
        }
        if (count >= 2) {
            return false;
        }
        if(count == 1) {
            num++;
        }
    }
    if (N != 1) {
        num++;
    }
    if(num == 3) {
        return true;
    }
    return false;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    for (int i = 1; i <= n; i++) {
        if (isSphenic(i)) {
            cout << i << endl;
        }
    }
    return 0;
}