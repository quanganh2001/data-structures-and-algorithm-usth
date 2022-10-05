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