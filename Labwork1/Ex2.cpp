// Write a pseudo-code then implement a program in C/C++ to enter a natural number n and find all sphenic numbers from 1 to n (using the function from Exercise 1). Calculate the complexity of your program.

// 1. array = {12, 13, 11, 9, 21, 45}
// 2. max = -99
// 3. temp = 0
// 4. for i from 0 to array.length
// 5. findMax(temp, array[i])
// 6. if(max < temp)
// 7. max = temp
// 8. print("Max number is ", max)
#include <iostream>
#include <math.h>

using namespace std;

bool isPrime(int a) {
    int count = 0;
    if (a == 1 || a == 0) {
        return 0;
    }
    for (int i = 2; i <= sqrt(a); i++) {
        if (a % i == 0) {
            count++;
        }
    }
    if (count == 0) {
        return true;
    }
    if (count != 0) {
        return false;
    }
}

int checkSphenic(int n) {
    int count = 0;
    int plus = 0;
    int arr[50000] = {};
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            arr[plus] = i;
            plus++;
        }
    }
    if (plus == 8) {
        for(int plus = 0; plus <= 5; plus++) {
            if (isPrime(arr[plus]) == true) {
                count++;
            }
        }
        if (count == 3) {
            return 1;
        }
    }
}

int main() {
    int n = 0;
    int overall = 0;
    cout << "Enter a number: ";
    cin >> n;
    for (int i = 2; i <= n; i++) {
        if (checkSphenic(i) == 1) {
            overall += 1;
        }
    }
    cout << overall << endl;
    return 0;
}
// Complexity: The complexity will be O(n) where n is the length of the sequence. This is because the findMax() function takes constant time, and traversing the sequence and finding the max form there takes n iterations, n is the size of the squence.