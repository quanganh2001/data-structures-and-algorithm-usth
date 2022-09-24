// Suppose that a polynomial function $a_0 + a_1*x + a_2*x^2 + ... + a_n*x^n$. Using list ADT, we would like to improve the computation of this function. The declaration of each element in the List should be as follows:

// - a value stands for a constant of each term $a_i (i = 0, ... ,n)$.
// - a degree indicates the degree of each term.

// Implement and test the program in C using a Static Array-based List to manage this polynomial function:

// - add new terms, verify that the old terms exists, if in the case, return the addition between the old and new ones i.e given the polynomial function $a_0 + a_1*x$, a new term is added into the function then the final term should be $a_0^{total} = a^{new}_0 + a_0$
// - remove a term from the function
// - enter a value for x then calculate the whole function
// - display the whole function on the screen
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