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