#include <iostream>
using namespace std;

typedef struct Node {
    int value;
    Node* next;
} Node;

typedef struct Queue {
    Node* firstElement;
    Node* lastElement;
} Queue;

Queue* createQueue() {
    Queue* q = new Queue;
    q->firstElement = nullptr;
    q->lastElement = nullptr;
    return q;
}

void enqueue(Queue* q, int value) {
    Node* newNode = new Node;
    newNode->value = value;
    newNode->next = nullptr;

    if (q->lastElement == nullptr) {
        q->firstElement = q->lastElement = newNode;
    } else {
        q->lastElement->next = newNode;
        q->lastElement = newNode;
    }
}

Node* dequeue(Queue* q) {
    if (q->firstElement == nullptr) {
        cout << "Queue is empty!" << endl;
        return nullptr;
    }

    Node* removedNode = q->firstElement;
    cout << "Removed element was: " << removedNode->value << endl;

    q->firstElement = q->firstElement->next;

    if (q->firstElement == nullptr) {
        q->lastElement = nullptr;
    }

    return removedNode;
}

void printQueue(Queue* q) {
    if (q->firstElement == nullptr) {
        cout << "Queue is empty!" << endl;
        return;
    }

    Node* current = q->firstElement;
    while (current != q->lastElement) {
        cout << current->value << " ";
        current = current->next;
    }
    cout << current->value << endl;
}

int main() {
    Queue* q = createQueue();
    int navigator = 0;
    int toAdd = 0;

    while (true) {
        cout << "Welcome to your queue! To view your queue, enter '1', to insert a value into your queue, enter '2', to remove the first element from your queue, enter '3', and to exit, enter '4'" << endl;
        cin >> navigator;

        while (navigator != 1 && navigator != 2 && navigator != 3 && navigator != 4) {
            cout << "\nYou did not provide a valid option! Try again!" << endl;
            cin >> navigator;
        }

        if (navigator == 1) {
            if (q->firstElement == nullptr) {
                cout << "Queue is empty!" << endl;
            } else {
                cout << "You chose to view the queue!" << endl;
                printQueue(q);
            }
        }

        if (navigator == 2) {
            cout << "You chose to insert! Please insert the number below:" << endl;
            cin >> toAdd;
            enqueue(q, toAdd);
        }

        if (navigator == 3) {
            if (q->firstElement == nullptr) {
                cout << "Queue is empty!" << endl;
            } else {
                cout << "You chose to remove the first element!" << endl;
                dequeue(q);
                printQueue(q);
            }
        }

        if (navigator == 4) {
            cout << "You chose to exit the queue!" << endl;
            break;
        }
    }

    return 0;
}