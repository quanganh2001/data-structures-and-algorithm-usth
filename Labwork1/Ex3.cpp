// Write a pseudo-code to verify a number is a perfect or not, then implement the pseudo-code into a program in C/C++ to enter a number and find all possible perfect numbers from 1 to n using reference/number. Calculate the complexity of your program.
#include <iostream>
using namespace std;
//pseudocode:
// BEGIN
//Get N
//sum <- 0
//for(i<-1;i<-N/2;i+1)
//if(N % i = 0) sum = sum + i
//if(sum=N) print true
//print false
//for(i=1;i<=1000;i+1)
//if function isperfectnumber of i is true then print i else false continue
//END

bool isPerfectNumber(int N) {
    int sum = 0;
    for (int i = 1; i <= N/2; i++) {
        if (N % i == 0) {
            sum += i;
        }
    }
    if (sum == N) {
        return true;
    }
    return false;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Below are all perfect numbers from 1 till " << n << ": \n";
    for (int i = 1; i <= n; i++) {
        if (isPerfectNumber(i)) {
            cout << i << endl;
        }
    }
    return 0;
}