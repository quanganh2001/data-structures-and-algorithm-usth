# Exercise 1
In this problem, we would like to implement a variation of the Insertion Sort algorithm. The algorithm differs from a bubble sort in that it sorts in both directions on each pass through the list. The algorithm is illustrated in the following figure:

[![image.png](https://i.postimg.cc/vZ70Q1wF/image.png)](https://postimg.cc/Wd3G814X)

- For the first step, we perform insertion sort from the index 1 to n (n is the number of elements in the array).
- In the next pass, we perform a reserved bubble sort from the index n to 1.
- The process is repeated until all the array is sorted.

Propose a pseudo-code to complete the Insertion Sort algorithm. Implement and test this algorithm in C/C++. Analyze and compute the complexity of this algorithm in the best, average and worst scenarios

```c
// In this problem, we would like to implement a variation of the Insertion Sort algorithm. The algorithm differs from a bubble sort in that it sorts in both directions on each pass through the list. The algorithm is illustrated in the following here:

/*
- For the first step, we perform insertion sort from the index 1 to n (n is the number of elements in the array).
- In the next pass, we perform a reserved bubble sort from the index n to 1.
- The process is repeated until all the array is sorted.
*/

// Propose a pseudo-code to complete the Insertion Sort algorithm. Implement and test this algorithm in C/C++. Analyze and compute the complexity of this algorithm in the best, average and worst scenarios
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void display(int arr[], int); 			// display all elements in the array.
int is_sorted(int arr[], int);			// check whether the array is sorted or not by using recursive method.
void sort_top(int arr[], int, int);		// sort from an initial index to a final index by a "increasing" for loop.
void sort_bottom(int arr[], int, int);	// nearly similar with the "sort_top" function. Now use a "decreasing" for loop.
void bubble_variation();				// main program here, includes: generating an array by users; sorting; displaying.
void complexity();						// print the complexity and my short explaination.

int main(){
	printf("\n*******A variation of the bubble sorting algorithm*******");
	printf("\nCreated: Nguyen Quang Anh - BA10-002 - Group 1\n");
	bubble_variation();
	complexity();
	return 0;
}

void bubble_variation(){
	int arr[100], n, num;
	int index = 0;
	// start generating an array by input from users
	printf("\n***Add some numbers to the array.");
	printf("\nEnter number of elements: "); scanf("%d", &n);

	for ( int i = 0; i < n; i++){
		printf("Enter a number: "); scanf("%d", &num);
		arr[i] = num;
	} 

	printf("\nYour original array is:\n"); display(arr, n);

	// start sorting here
	int length = n - 1; // the biggest index
	int i = 0; 			// the smallest index, and also be the number of steps
	bool check = false; 

	while (check == false){
		sort_top(arr, index, length); 		// sort from top
		length -= 1;	// decrease the biggest index, because the greatest element is in the right place.

		printf("\nPass %d, from top: \n", ++i); display(arr,n);

		sort_bottom(arr, length, index); 	// sort from bottom
		index += 1;		// increase the smallest index, because the smallest element is in the right place.

		printf("\nPass %d, from bottom: \n", ++i); display(arr,n);

		check = is_sorted(arr,n); // maintain the loop
	}

	printf("\n\nThe sorted array is: "); display(arr, n);
	printf("\nThe algorithm take %d pass(es).", i);

}

void display(int arr[], int n){
	int i;
	printf("\t");
	for (i = 0; i < n; i++){
		printf("   %d   ", arr[i]);
	}
}

int is_sorted(int arr[], int n){
	if ( n == 1 || n == 0) // Base case: when there is 0 or 1 items in the array, it means the array is sorted.
		return 1;
	if ( arr[n-1] < arr[n-2]) // check all pairs here
		return 0;
	return is_sorted(arr, n-1);
}

void sort_top(int arr[], int from, int to){
	int i, temp;
	for ( i = from; i < to ; i++){ // "forward" loop
		if (arr[i] > arr[i+1]){
			temp = arr[i]; arr[i] = arr[i+1]; arr[i+1] = temp; //swap 2 values
		}
	}
}


void sort_bottom(int arr[], int from, int to){
	int i, temp;
	for (i = from; i > to; i--){ // "downward" loop
		if (arr[i] < arr[i-1]){
			temp = arr[i]; arr[i] = arr[i-1]; arr[i-1] = temp; //swap 2 values
		}
	}
}

void complexity(){
	printf("\n\n\t*****Complexity*****");
	printf("\n***Best case: O(n)");
	printf("\n- In the best case (the input is a sorted array), my algorithm need");
	printf("to pass through 3 \"for\" loops with complexity O(n) only *1 time.");
	printf("\n- We have: O(3n) = O(n)");
	printf("\n***Worst case: O(n^2)");
	printf("\n- Similarly my algorithm need to pass through 3 loops for *n times.");
	printf("\n***Average case: O(n^2)");
}
```
Output:
```txt
*******A variation of the bubble sorting algorithm*******
Created: Nguyen Quang Anh - BA10-002 - Group 1

***Add some numbers to the array.
Enter number of elements: 8
Enter a number: 99
Enter a number: 55 
Enter a number: 44
Enter a number: 22
Enter a number: 66
Enter a number: 88
Enter a number: 33
Enter a number: 11

Your original array is:
           99      55      44      22      66      88      33      11
Pass 1, from top:
           55      44      22      66      88      33      11      99
Pass 2, from bottom:
           11      55      44      22      66      88      33      99
Pass 3, from top:
           11      44      22      55      66      33      88      99
Pass 4, from bottom:
           11      22      44      33      55      66      88      99
Pass 5, from top:
           11      22      33      44      55      66      88      99
Pass 6, from bottom:
           11      22      33      44      55      66      88      99

The sorted array is:       11      22      33      44      55      66      88      99
The algorithm take 6 pass(es).

        *****Complexity*****
***Best case: O(n)
- In the best case (the input is a sorted array), my algorithm needto pass through 3 "for" loops with complexity O(n) only *1 time.
- We have: O(3n) = O(n)
***Worst case: O(n^2)
- Similarly my algorithm need to pass through 3 loops for *n times.
***Average case: O(n^2)
```
# Exercise 2
Re-implement Exercise 1 using a linear data structure.: List, Stack, Queue. Justify your choice of data structure.
```c
// Re-implement Exercise 1 using a linear data structure.: List, Stack, Queue. Justify your choice of data structure.
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *start; // the global list to save data
void display(struct node *); // display all the item
void push(struct node **, int); // push new node ino the list
void Split(struct node *, struct node **, struct node **); // split all the linked list
struct node *mergeLists(struct node *, struct node *); // merge 2 small lists into 1 using recursive method, then return list
void mergeSort(struct node**);
void program();

int main() {
    printf("\n*******Merge sort implemented by Linked list*******");
    printf("\nCreated: Nguyen Quang Anh - BA10-002 - Group 1\n");
    program();
    
    return 0;
}

void program() {
    struct node *head = NULL;
    int i;
    printf("\n***Add some number to the list: ");
    printf("\n***Enter -1 to exit.\n");
    while (i != -1){
        printf("Enter a number: ");
        scanf("%d", &i);
        if(i != -1)
            push(&head, i);
    }
    printf("\nYour original list is: ");
    display(start);
    
    printf("\n\n***Start spliting the list: ");
    mergeSort(&start);
    
    printf("The sorted list is: ");
    display(start);
}

void display(struct node *top) {
    struct node *ptr = top;
    while (ptr != NULL){
        printf(" %d ", ptr -> data);
        ptr = ptr -> next;
    }
    printf("\t"); // just for formatting
}

void push(struct node **head, int data) { // same as other functions in previous labwork
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node -> data = data;
    new_node -> next = NULL;
    
    if((*head) == NULL){
        *head = new_node;
        start = *head;
    }
    else{
        (*head) -> next = new_node;
        *head = new_node;
    }
}

void Split(struct node *top, struct node **front, struct node **back){
	struct node *fast; 
	struct node *slow;

	if (top == NULL || top -> next == NULL){
		*front = top;
		*back = NULL;
	}
	else { 
		printf("\n");
		slow = top;
		fast = top -> next;

		while (fast != NULL){ 	// this loop finds the middle of the list
			fast = fast -> next;
			if (fast != NULL){
				slow = slow -> next;
				fast = fast -> next;
			}
		}
		*front = top; 		  // set the first half of the list to "front"
		*back = slow -> next; // set the second half of the list to "back"
		slow -> next = NULL;  // cut the list

		printf("\nFront: "); display(*front);
		printf("Back: "); display(*back);	
	}
}

struct node *mergeLists(struct node *a, struct node *b){
    struct node *finalList = NULL;
    if (a == NULL) // If one of 2 lists is empty -> copy the rest
        return b; // of the other to the list
    else if (b == NULL)
        return a;
    
    if (a -> data <= b -> data) { // Compare the value of 2 first nodes in each list
        finalList = a; // then place them in the right place.
        finalList -> next = mergeLists(a -> next, b);
    }
    else{
        finalList = b;
        finalList -> next = mergeLists(a, b -> next);
    }
    return finalList;
}

void mergeSort(struct node **source){
	struct node *head;  // save the whole list here
	struct node *a, *b; // "storage" lists to save halves after spliting.

	head = *source;
	if (head == NULL || head -> next == NULL) // base case
		return;

	Split(head, &a, &b);	// Spliting the whole list
	printf("\n");

	mergeSort(&a);
	mergeSort(&b);

	display(a); printf("\t"); display(b); // dispaly the process

	printf("\n");

	*source = mergeLists(a,b); // add the "small" sorted list to the "source" after each sorting and merging.
	printf("--->Final: "); display(*source); printf("\n\n");
}
```
Output:
```txt
*******Merge sort implemented by Linked list*******
Created: Nguyen Quang Anh - BA10-002 - Group 1

***Add some number to the list:
***Enter -1 to exit.
Enter a number: 99
Enter a number: 55
Enter a number: 44
Enter a number: 22
Enter a number: 66
Enter a number: 88
Enter a number: 33
Enter a number: 11
Enter a number: -1

Your original list is:  99  55  44  22  66  88  33  11

***Start spliting the list:

Front:  99  55  44  22  Back:  66  88  33  11


Front:  99  55  Back:  44  22


Front:  99      Back:  55
 99              55
--->Final:  55  99



Front:  44      Back:  22
 44              22
--->Final:  22  44

 55  99                  22  44
--->Final:  22  44  55  99



Front:  66  88  Back:  33  11


Front:  66      Back:  88
 66              88
--->Final:  66  88



Front:  33      Back:  11
 33              11
--->Final:  11  33

 66  88                  11  33
--->Final:  11  33  66  88

 22  44  55  99                  11  33  66  88
--->Final:  11  22  33  44  55  66  88  99

The sorted list is:  11  22  33  44  55  66  88  99
```