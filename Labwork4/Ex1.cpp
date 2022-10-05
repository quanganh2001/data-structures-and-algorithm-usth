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