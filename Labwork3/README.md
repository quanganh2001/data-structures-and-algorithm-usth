# Exercise 1
Suppose that we would like to implement a queue system for a commercial website. Given that the website offers 3 items for sale (or a list of items), each item has a limit quantity in stock. Implement a queue of customers, each customer can buy only a few number product among the available three items.

- Determine the item name, their quantity in stock;
- Specify a queue of n customers, each customer can buy k products from one item (k is different for each customer);
- Customers take turn to enter (enqueue) and leave (dequeue) the queue according to the FIFO order to purchase wanted products;
- If a customer successfully purchased products, then display a message and reduce the number of products in stock: otherwise, if the item has been run out, display a warning message.

Implement the above problems in C/C++ using a Queue data structure. Write a main function for testing all written functions.
```cpp
#include <iostream>
using namespace std;

typedef struct cust {
    int custno;
    int Limit;
}cust ;

class Queue {
    private:
        int firstNode;
        int lastNode;
        cust queueArray[100];
    
    public:
        Queue();
        void enQueue(int custLimit);
        void printQueue();
        void getQueue(int custId, cust &data);
        void deQueue();
};

Queue::Queue() {
    // init to -1 instead of 0 when empty since 0 is used as an index
    // these track first and last nodes in array implementation
    firstNode = -1;
    lastNode = -1;
}

void Queue::enQueue(int custLimit) {
    if(firstNode == -1){
        firstNode++;
    }
    
    // cout << firstNode << endl;
    // cout << lastNode << endl;
    queueArray[++lastNode].Limit = custLimit;
    // cout << firstNode << endl;
    // cout << lastNode << endl;
    
    // custID++;
    queueArray[lastNode].custno = lastNode;
}

void Queue::printQueue() {
    if (firstNode != -1){
        cout << "\nCurrent Queue: \n";
        // print stack from top down
        cout << "\t - Last -\n";
        for (int i = lastNode; i >= firstNode; i--){
            cout << "Customer ID: " << queueArray[i].custno << endl;
            cout << "Customer Limit: " << queueArray[i].Limit << endl;
        }
        cout << "\t - First -\n\n";
    } else {
        cout << "The Queue is Empty.\n\n";
    }
}

void Queue::deQueue() {
    if (firstNode == -1){
        cout << "\nQueue is empty, no nodes are available for dequeue.\n\n";
        return;
    } else if (firstNode == lastNode){
        cout << queueArray[firstNode].custno << " has existed the queue, queue is now empty\n\n";
        // last node is up for dequeue, not to -1 to indicate empty queue
        firstNode = -1;
        lastNode = -1;
    } else {
        // lose the first node to dequeue
        cout << queueArray[firstNode].custno << " has existed the queue.\n\n";
        firstNode++;
    }
}

int main() {
    Queue q;
    bool inUse = true;
    int operation = -1;
    int custLimit;
    int n = 0;
    int item1, item2, item3;
    cout << "Input the Quantity of Item no 1: ";
    cin >> item1;
    cout << "Input the Quantity of Item no 2: ";
    cin >> item2;
    cout << "Input the Quantity of Item no 3: ";
    cin >> item3;
    
    cout << "Items List: \n";
    cout << "-------------------" << endl;
    cout << " | " << "Item ID" << " | " << "Quantity" << " | " << endl;
    cout << "-------------------" << endl;
    cout << " | " << "ID: 1 " << " | " << "  " << item1 << "  " << " | " << endl;
    cout << "-------------------" << endl;
    cout << " | " << "ID: 2 " << " | " << "  " << item2 << "  " << " | " << endl;
    cout << "-------------------" << endl;
    cout << " | " << "ID: 3 " << " | " << "  " << item3 << "  " << " | " << endl;
    cout << "-------------------" << endl;
    
    cout << "Select stack operation by entering the corresponding number: \n";
    cout << "\t1. Enqueue\n";
    cout << "\t2. Dequeue\n";
    cout << "\t3. Print current Queue\n";
    cout << "\t4. Exit\n";
    do {
        cout << "Enter operation number: ";
        // read user selection
        cin >> operation;
        if (operation == 1){ // push
            cout << "Enter an integer to add to the end of the queue: ";
            cin >> custLimit;
            q.enQueue(custLimit);
            n++;
        } else if (operation == 2){ // pop
            q.deQueue();
            n--;
        } else if (operation == 3){ // print stack
            q.printQueue();
        } else { // exit
            cout << "Existing Queue program.\n";
            inUse = false;
        }
    } while (inUse);
    
    int K;
    cust Customer;
    
    for(int i = 0; i < n; i++){
        q.getQueue(i, Customer);
        
        INPUT_A;
        cout << "Input the quantity for customer " << Customer.custno << " : ";
        cin >> K;
        if (K > Customer.Limit){
            cout << "The quantity exceed limit please do it again" << endl;
            goto INPUT_A;
        }
        
        int item_no;
        cout << "Input the item no(1,2,3): ";
        cin >> item_no;
        
        if(item_no == 1){
            if(K > item1){
                cout << "Warning: Item no 1 is out of stack!" << endl;
            }
            
            else {
                item1-=K;
                cout << "Customer ID: " << Customer.custno << " successfully purchased quantity " << K << " of Item no 1" << endl;
            }
            q.deQueue();
        }
        
        else if(item_no == 2){
            if(K > item2){
                cout << "Warning: Item no 2 is out of stack!" << endl;
            }
            
            else {
                item2-=K;
                cout << "Customer ID: " << Customer.custno << " successfully purchased quantity " << K << " of Item no 2" << endl;
            }
            q.deQueue();
        }
        
        else{
            if(K > item3){
                cout << "Warning: Item no 3 is out of stack!" << endl;
            }
            
            else {
                item3-=K;
                cout << "Customer ID: " << Customer.custno << " successfully purchased quantity " << K << " of Item no 3" << endl;
            }
            q.deQueue();
        }
    }
}
```
That not completely due to 2 errors
# Exercise 2
In this problem, we try to implement the undo/redo mechanism using two stacks. Choose one method to implement to implement a Stack data structure (Array-based Stack or Stack using Linked List) to implement the above problem.

- String of characters are stored in the Stack data structure;
- If a character is popped from Undo stack, then it is immediately pushed into Redo stack; and vice-versa;

Write the main function for testing all written functions (init(), display(), push(), pop(),..)

```cpp
#include <iostream>
using namespace std;

class Stack {
    private:
        int topIndex;
        string stackArray[100];
    public:
        Stack();
        void printStack();
        void push(string data);
        void pop();
        void temp(string &m_data);
};

// constructor
Stack::Stack() {
    // Init
    topIndex = -1;
    cout << "Stack initialized.\n";
}

void Stack::printStack() {
    if (topIndex != -1){
        cout << "Current stack:\n";
        // print stack from top down
        cout << "\tTop\n";
        for (int i = topIndex; i >= 0; i--){
            cout << "\t";
            cout << stackArray[i] << endl;
        }
        cout << "\tBottom\n";
    } else {
        cout << "The stack is empty.\n";
    }
}

// push/add top function
void Stack::push(string data) {
    // increment before using to move -1 to 0 first time
    // add consistantly increment the value when pushing
    // to the stack
    stackArray[++topIndex] = data;
    cout << "Pushed " << data << endl;
}

// pop/remove top function
void Stack::pop() {
    if (topIndex != -1) {
        // Decrement top to lose
        // it can just be rewritten by a stack later
        topIndex--;
        cout << "Popped " << stackArray[topIndex+1] << endl;
    } else { // top index is set to - 
        cout << "Stack is empty. no nodes to remove.\n";
    }
}

void Stack::temp(string &m_data){
    m_data = stackArray[topIndex];
}

void move(Stack &S1, Stack &S2){
    string m_data;
    S1.temp(m_data);
    S1.pop();
    S2.push(m_data);
}

int main() {
    // create Stack
    Stack Undo, Redo;
    // create bool
    bool inUse = true;
    // user operation
    int operation = -1;
    // user data for push function
    string data;
    // Run stack functionality until error or invalid input.
    cout << "Select stack operation by entering the corresponding number: \n";
    cout << "\t1. Push\n";
    cout << "\t2. Pop(Undo -> Redo)\n";
    cout << "\t3. Pop2(Redo -> Undo)\n";
    cout << "\t4. Print current stack\n";
    cout << "\t5. Exit\n";
    
    do {
        cout << "Enter operation number: ";
        // read user selection
        cin >> operation;
        
        if (operation == 1){ // push
            cout << "Enter a word to push to the top of the stack: ";
            cin >> data;
            Undo.push(data);
        }
        
        else if (operation == 2) { // pop
            move(Undo, Redo);
        }
        
        else if (operation == 3) { // pop2
            move(Redo, Undo);
        }
        
        else if (operation == 4) { // print stack
            cout << "\nUndo Stack: " << endl;
            Undo.printStack();
            cout << "\nRedo Stack: " << endl;
            Redo.printStack();
        }
        
        else { // exit
            cout << "Existing stack program.\n";
            inUse = false;
        }
    } while (inUse);
    
    return 42; // return the correct answer on proper exit of main
}
```
Output:
```txt
Stack initialized.
Stack initialized.
Select stack operation by entering the corresponding number: 
        1. Push
        2. Pop(Undo -> Redo)
        3. Pop2(Redo -> Undo)
        4. Print current stack
        5. Exit
Enter operation number: 1
Enter a word to push to the top of the stack: a  
Pushed a
Enter operation number: 1
Enter a word to push to the top of the stack: ab
Pushed ab
Enter operation number: 1
Enter a word to push to the top of the stack: abc
Pushed abc
Enter operation number: 1
Enter a word to push to the top of the stack: abcd
Pushed abcd
Enter operation number: 1
Enter a word to push to the top of the stack: abcde
Pushed abcde
Enter operation number: 2
Popped abcde
Pushed abcde
Enter operation number: 3
Popped abcde
Pushed abcde
Enter operation number: 4

Undo Stack:
Current stack:
        Top
        abcde
        abcd
        abc
        ab
        a
        Bottom

Redo Stack:
The stack is empty.
Enter operation number: 2
Popped abcde
Pushed abcde
Enter operation number: 4

Undo Stack:
Current stack:
        Top
        abcd
        abc
        ab
        a
        Bottom

Redo Stack:
Current stack:
        Top
        abcde
        Bottom
Enter operation number: 3
Popped abcde
Pushed abcde
Enter operation number: 4

Undo Stack:
Current stack:
        Top
        abcde
        abcd
        abc
        ab
        a
        Bottom

Redo Stack:
The stack is empty.
Enter operation number: 5
Existing stack program.
```