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