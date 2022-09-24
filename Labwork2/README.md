# Exercise 1
Suppose that a polynomial function $a_0 + a_1*x + a_2*x^2 + ... + a_n*x^n$. Using list ADT, we would like to improve the computation of this function. The declaration of each element in the List should be as follows:

- a value stands for a constant of each term $a_i (i = 0, ... ,n)$.
- a degree indicates the degree of each term.

Implement and test the program in C using a Static Array-based List to manage this polynomial function:

- add new terms, verify that the old terms exists, if in the case, return the addition between the old and new ones i.e given the polynomial function $a_0 + a_1*x$, a new term is added into the function then the final term should be $a_0^{total} = a^{new}_0 + a_0$
- remove a term from the function
- enter a value for x then calculate the whole function
- display the whole function on the screen
*/
```cpp
#include <iostream>
#include <math.h>
using namespace std;
struct function {
    int degree;
    float value;
    function *next;
};

function* createNode(float value, int degree);
function* add(function* head, function* p);
function* findDegree(function* head, int degree);
function* findTerm(function* head, float value, int degree);
function* removeTerm(function* head, float value, int degree);
float calculateValue(function* head, float value);
void freeList(function*head);
void printList(function* head);

function* createNode(float value, int degree) {
    function* pNew = new function();
    pNew -> value = value;
    pNew -> degree = degree;
    return pNew;
}

function* add(function* head, function* p) {
    function* pTemp = head;
    if (head == NULL) {
        head = p;
        p -> next = NULL;
    }
    else //TH2 danh sach ban dau khong phai rong
    {
        function* temp = findDegree(head, p -> degree);
        if (temp == NULL) {
            if (head -> degree > p -> degree) {
                p -> next = head;
                head = p;
            }
            else {
                while (pTemp -> next != NULL && (head -> degree < p -> degree)) pTemp = pTemp -> next;
                p -> next = pTemp -> next;
                pTemp -> next = p;
            }
        }
        else temp -> value += p -> value;
    }
    return head;
}

function* findDegree(function* head, int degree) {
    function* pTemp = head;
    while (pTemp != NULL && (pTemp -> degree != degree)) pTemp = pTemp -> next;
    return pTemp;
}

function* findTerm(function* head, float value, int degree) {
    function *pTemp = head;
    while (pTemp != NULL && pTemp -> degree != degree && pTemp -> value != value) pTemp = pTemp -> next;
    return pTemp;
}

function* removeTerm(function* head, float value, int degree) {
    function* pTemp = findTerm(head, value, degree);
    function* qTemp = head;
    
    if (pTemp == NULL) return qTemp;
    if (pTemp == qTemp) qTemp = qTemp -> next;
    else
    {
        function *pre = head;
        while (pre -> next != pTemp) pre = pre -> next;
        pre -> next = pTemp -> next;
    }
    free(pTemp);
    return qTemp;
}

float calculateValue(function* head, float x) {
    float sum = 0;
    function* p = head;
    while (p != NULL)
    {
        sum += (pow(x, p -> degree) * p -> value);
        p = p -> next;
    }
    return sum;
}

void printList(function* head) {
    function* p =head;
    cout << "f(x) = ";
    cout << p -> value << "*x^" << p -> degree;
    p = p -> next;
    while (p != NULL)
    {
        if (p -> value > 0) {
            cout << "+" << p -> value << "*x^" << p -> degree;
        }
        else
        {
            cout << p -> value << "*x^" << p -> degree;
        }
        p = p -> next;
    }
    printf("\n");
}

void freeList(function* head) {
    while (head != NULL)
    {
        function *p = head -> next;
        free(head);
        head = p;
    }
}

int main() {
    function* head = NULL;
    
    // add a term
    function* p1 = createNode(3, 6);
    head = add(head, p1);
    
    function* p2 = createNode(-4, 7);
    head = add(head, p2);
    
    function* p3 = createNode(-4, 4);
    head = add(head, p3);
    
    function* p4 = createNode(-5, 8);
    head = add(head, p4);
    
    function* p5 = createNode(9, 4);
    head = add(head, p5);
    
    // print list
    printList(head);
    
    // search
    function* p = findTerm(head, -5, 8);
    cout << p -> value << "*x^" << p -> degree << endl;
    
    // remove
    head = removeTerm(head, -5, 8);
    printList(head);
    
    // calculate f(2)
    cout << "f(2) = " << calculateValue(head, 2) << endl;
    
    // delete list
    freeList(head);
    
    return 0;
}
```
Output
```txt
f(x) = 5*x^4+3*x^6-4*x^7-5*x^8
-5*x^8
f(x) = 5*x^4+3*x^6-4*x^7
f(2) = -240
```
# Exercise 2
Assume that a railway train has N railroad cars attached together such as $car_1, car_2, car_3,...,car_N. A train can be considered as a list and each car corresponding to a node in this list.

- Each car carries a number of passengers (int type) and has a name (char type). Both variables are user-defined values.
- If there are any cars that don’t have any passengers, they should be removed from the train
- It is possible to add new cars to the train.
- A function is available to display all cars' information or the length of the train.

Implement a program in C using Linked List to manage the train and test all functions
```c
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

struct node{
	int NUM;
	char NAME[100];
	struct node *next;
};

struct node *start = NULL;
struct node *create_ll(struct node *); 	// We create the linked list here
struct node *add_before(struct node *);	// I decide to make 3 different addition functions
struct node *add_beg(struct node *);	// so the code will be much easier to read
struct node *add_end(struct node *);
struct node *delete_zero(struct node *);// delete the car with 0 passenger
struct node *display(struct node *);	// show all the cars and their names

struct node *create_ll(struct node *start){
	struct node *new_node, *ptr;
	int num;
	char name[100];
	printf("\nEnter num = -1 to end");
	printf("\nEnter num: "); scanf("%d", &num);
	printf("Enter name: "); scanf("%s", &name);

	while(num != -1){
		new_node = (struct node *)malloc(sizeof(struct node));
		new_node -> NUM= num;
		strcpy(new_node ->NAME, name);
		if (start == NULL){
			new_node -> next = NULL;
			start = new_node;
		}
		else{
			ptr = start;
			while (ptr -> next != NULL)
				ptr = ptr -> next;
			ptr -> next = new_node;
			new_node -> next = NULL;
		}
		printf("\nEnter num: "); scanf("%d", &num);
		printf("Enter name: "); scanf("%s", &name);
	}
	return start;
}

struct node *add_before(struct node *start){
	struct node *new_node, *ptr, *preptr;
	int num, pos;
	char name[100];
	

	printf("\nEnter num: ");
	scanf("%d", &num);
	printf("Enter name: ");
	scanf("%s", name);
	printf("Enter the position before which you want to insert: ");
	scanf("%d", &pos);
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node -> NUM = num;
	strcpy(new_node -> NAME, name);

	ptr = start;
	while (ptr -> NUM != pos){
		preptr = ptr;
		ptr = ptr -> next;
	}
	preptr -> next = new_node;
	new_node -> next = ptr;
	return start;
}

struct node *add_beg(struct node *start){
	struct node *new_node;
	int num;
	char name[100];

	printf("\nEnter num: "); scanf("%d", &num);
	printf("\nEnter name: "); scanf("%s", name);

	new_node = (struct node *)malloc(sizeof(struct node));
	new_node -> NUM = num;
	strcpy(new_node -> NAME, name);
	new_node -> next = start;
	start = new_node;
	return start;
}

struct node *add_end(struct node *start){
	struct node *ptr, *new_node;
	int num;
	char name[100];
	printf("\nEnter num: "); scanf("%d", &num);
	printf("\nEnter name: "); scanf("%s", name);

	new_node = (struct node *)malloc(sizeof(struct node));
	new_node -> NUM = num;
	strcpy(new_node -> NAME, name);

	new_node -> next = NULL;
	ptr = start;
	while (ptr -> next != NULL)
		ptr = ptr -> next;
	ptr -> next = new_node;
	return start;
}

struct node *delete(struct node *start){
	struct node *ptr;
	ptr = start;
	start = start -> next;
	free(ptr);
	return start;
}

struct node *delete_zero(struct node *start){
	struct node *ptr, *preptr;
	ptr = start;
	
	if (ptr -> NUM == 0){
		start = delete(start);
		return start;
	}
	else {
		while (ptr -> NUM != 0){
			preptr = ptr;
			ptr = ptr -> next;
		}
		preptr -> next = ptr -> next;
		free(ptr);
		return start;
	}
}

struct node *display(struct node *start){
	struct node *ptr;
	ptr = start;
	printf("\t\tList of all cars:\n");
	while (ptr != NULL){
		printf("\t \t%d %s\n", ptr -> NUM, ptr -> NAME);
		ptr = ptr -> next;
	}
	return start;
}

int main(){
	int x, addtype;

	while( x!= 5){
		printf("\n1. Create a linked list of cars. ");
		printf("\n2. Add a new car into the train. ");
		printf("\n3. Display all cars's information.");
		printf("\n4. Delete cars that have 0 passenger.");
		printf("\n5. Exit.");
		printf("\n\n \tEnter your option: ");
		scanf("%d", &x);
	
		switch(x){
			case 1: start = create_ll(start); break;
			case 2: 
				printf("\n1. Insert at the begining.");
				printf("\n2. Insert before a position.");
				printf("\n3. Insert at the end.");
				printf("\nYour choice: "); scanf("%d", &addtype);
				switch (addtype){
					case 1: start = add_beg(start); break;
					case 2: start = add_before(start); break;
					case 3: start = add_end(start); break;
				} break;
			case 3: start = display(start); break;
			case 4: start = delete_zero(start); break;
		}
	}
	return 0;
}
```
Output:
````txt
1. Create a linked list of cars.     
2. Add a new car into the train.     
3. Display all cars's information.   
4. Delete cars that have 0 passenger.
5. Exit.

        Enter your option: 1

Enter num = -1 to end
Enter num: 0
Enter name: ABC

Enter num: 1
Enter name: BMW

Enter num: 2
Enter name: Vinfast

Enter num: 3
Enter name: Toyota

Enter num: 4
Enter name: Volvo

Enter num: -1
Enter name: fsds

1. Create a linked list of cars.
2. Add a new car into the train.
3. Display all cars's information.
4. Delete cars that have 0 passenger.
5. Exit.

        Enter your option: 2

1. Insert at the begining.
2. Insert before a position.
3. Insert at the end.
Your choice: 3

Enter num: 5

Enter name: Mazda

1. Create a linked list of cars.
2. Add a new car into the train.
3. Display all cars's information.
4. Delete cars that have 0 passenger.
5. Exit.

        Enter your option: 3
                List of all cars:
                0 ABC
                1 BMW
                2 Vinfast
                3 Toyota
                4 Volvo
                5 Mazda

1. Create a linked list of cars.
2. Add a new car into the train.
3. Display all cars's information.
4. Delete cars that have 0 passenger.
5. Exit.

        Enter your option: 2

1. Insert at the begining.
2. Insert before a position.
3. Insert at the end.
Your choice: 1

Enter num: 0

Enter name: DFSDF

1. Create a linked list of cars.
2. Add a new car into the train.
3. Display all cars's information.
4. Delete cars that have 0 passenger.
5. Exit.

        Enter your option: 4

1. Create a linked list of cars.
2. Add a new car into the train.
3. Display all cars's information.
4. Delete cars that have 0 passenger.
5. Exit.

        Enter your option: 3
                List of all cars:
                0 ABC
                1 BMW
                2 Vinfast
                3 Toyota
                4 Volvo
                5 Mazda

1. Create a linked list of cars.
2. Add a new car into the train.
3. Display all cars's information.
4. Delete cars that have 0 passenger.
5. Exit.

        Enter your option: 4

1. Create a linked list of cars.
2. Add a new car into the train.
3. Display all cars's information.
4. Delete cars that have 0 passenger.
5. Exit.

        Enter your option: 3
                List of all cars:
                1 BMW
                2 Vinfast
                3 Toyota
                4 Volvo
                5 Mazda

1. Create a linked list of cars.
2. Add a new car into the train.
3. Display all cars's information.
4. Delete cars that have 0 passenger.
5. Exit.

        Enter your option: 2

1. Insert at the begining.
2. Insert before a position.
3. Insert at the end.
Your choice: 2

Enter num: 2
Enter name: Yomo
Enter the position before which you want to insert: 3

1. Create a linked list of cars.
2. Add a new car into the train.
3. Display all cars's information.
4. Delete cars that have 0 passenger.
5. Exit.

        Enter your option: 3
                List of all cars:
                1 BMW
                2 Vinfast
                2 Yomo
                3 Toyota
                4 Volvo
                5 Mazda

1. Create a linked list of cars.
2. Add a new car into the train.
3. Display all cars's information.
4. Delete cars that have 0 passenger.
5. Exit.

        Enter your option: 2

1. Insert at the begining.
2. Insert before a position.
3. Insert at the end.
Your choice: 1

Enter num: 1

Enter name: MO

1. Create a linked list of cars.
2. Add a new car into the train.
3. Display all cars's information.
4. Delete cars that have 0 passenger.
5. Exit.

        Enter your option: 3
                List of all cars:
                1 MO
                1 BMW
                2 Vinfast
                2 Yomo
                3 Toyota
                4 Volvo
                5 Mazda

1. Create a linked list of cars.
2. Add a new car into the train.
3. Display all cars's information.
4. Delete cars that have 0 passenger.
5. Exit.

        Enter your option: 5
````