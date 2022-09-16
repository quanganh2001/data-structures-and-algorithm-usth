# Exercise 1

Write a program to enter a natural number n and find all sphenic numbers from 1 to n. Calculate the complexity of your program.

Note: A sphenic number is a product of pqr where p, q and r are three distinct prime numbers. Example 30 = 2 * 3 * 5; 42 = 2 * 3 * 7; 66 = 2 * 3 * 11

## Source Code

```cpp
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
        if (count >= 2) return false;
        if (count == 1) num++;
    }
    if (N != 1) num++;
    if(num == 3) return true;
    return false;
}
int main () {
  for (int i = 1; i <= 1000; i++) {
        if (isSphenic(i)) cout << i << endl;
    }
    // Complexity: O(can N *logN)
}
```

Output

```
30
42
66
70
78
102
105
110
114
130
138
154
165
170
174
182
186
190
195
222
230
231
238
246
255
258
266
273
282
285
286
290
310
318
322
345
354
357
366
370
374
385
399
402
406
410
418
426
429
430
434
435
438
442
455
465
470
474
483
494
498
506
518
530
534
555
561
574
582
590
595
598
602
606
609
610
615
618
627
638
642
645
646
651
654
658
663
665
670
678
682
705
710
715
730
741
742
754
759
762
777
782
786
790
795
805
806
814
822
826
830
834
854
861
874
885
890
894
897
902
903
906
915
935
938
942
946
957
962
969
970
978
986
987
994
```

## User Input

```cpp
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
```

Output

```
Enter a number: 200
30
42
66
70
78
102
105
110
114
130
138
154
165
170
174
182
186
190
195
```

# Exercise 2

Complete the following function: void findMax(int &max, int a) which assigns value 'a' to 'max' if a > max. Write a pseudo-code then implement a program in C/C++ to find a maximum in sequence of numbers using this function. Calculate the complexity of your program.

```cpp
// Complete the following function: void findMax(int &max, int a) which assigns value 'a' to 'max' if a > max. Write a pseudo-code then implement a program in C/C++ to find a maximum in sequence of numbers using this function. Calculate the complexity of your program.
#include <iostream>
using namespace std;

void findMax(int& max, int a) {
    if (a > max) {
        max = a;
    }
}

int main() {
    int a[] = { 1,4,2,6,8,9 };
    int& max = a[0];

    for (int i = 0; i < 6; i++) {
        findMax(max, a[i]);
    }
    cout << max << endl;
    return 0;
}
//Complexity: O(N)
```

Output is 9

# Exercise 3

Write a pseudo-code to verify a number is a perfect or not, then implement the pseudo-code into a program in C/C++ to enter a number and find all possible perfect numbers from 1 to n using reference/number. Calculate the complexity of your program.

Note: A perfect number is a number that is equal to the sum of its divisor. For example: 6 = 1 + 2 + 3; 28 = 14 + 7 + 4 + 2 + 1

## Source Code

```cpp
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
        if (N % i == 0) sum += i;
    }
    if (sum == N) return true;
    return false;
}
int main () {
  for (int i = 1; i <= 1000; i++) {
        if (isPerfectNumber(i)) cout << i << endl;
    }
    // Complextity: O(N/2)
}
```

Output

```
6
28
496
```

## User Input

```cpp
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
```

Output

```
Enter a number: 1000
Below are all perfect numbers from 1 till 1000: 
6
28
496
```