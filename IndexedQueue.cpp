#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

typedef struct queue {
    int index = 0;
    int front = -1;
    int elements[MAX_SIZE];
} queue;

int enqueue(queue* p, int value) {
    if (p->index == MAX_SIZE) {
        cout << "Queue is full!" << endl;
        return -1;
    } else if (p->front == -1) {
        p->front = 0;
        p->elements[p->index] = value;
        p->index = p->index + 1;
        return value;
    } else {
        p->elements[p->index] = value;
        p->index = p->index + 1;
        return value;
    }
}

int dequeue(queue* p) {
    if (p->index == 0) {
        cout << "Queue is empty!" << endl;
        return -1;
    } else {
        int removed_value = p->elements[p->front];
        for (int i = p->front; i < p->index - 1; i++) {
            p->elements[i] = p->elements[i + 1];
        }
        cout << "Removed number was [" << removed_value << "]" << endl;
        p->index--;
        return removed_value;
    }
}

void printQueue(queue* p) {
    for (int i = 0; i < p->index; i++) {
        cout << "[" << p->elements[i] << "]-> ";
    }
    cout << endl;
}

int main() {
    queue my_queue;
    int navigator = 0;
    int added_number = 0;

    while (true) {
        cout << "Welcome to your queue! To add an element, enter '1', to remove the first element, enter '2', to view your queue, enter '3', and to exit, enter '4'" << endl;
        cin >> navigator;

        while (navigator != 1 && navigator != 2 && navigator != 3 && navigator != 4) {
            cout << "\nYou did not provide a valid option! Try again!" << endl;
            cin >> navigator;
        }

        if (navigator == 1) {
            cout << "You chose to insert! Insert a number below!" << endl;
            cin >> added_number;
            enqueue(&my_queue, added_number);
        }

        if (navigator == 2) {
            cout << "You chose to remove the first element!" << endl;
            if (my_queue.front == -1) {
                cout << "Queue is empty!" << endl;
            } else {
                dequeue(&my_queue);
            }
        }

        if (navigator == 3) {
            cout << "You chose to view the queue!" << endl;
            if (my_queue.front == -1) {
                cout << "Queue is empty!" << endl;
            } else {
                printQueue(&my_queue);
            }
        }

        if (navigator == 4) {
            cout << "You chose to exit!" << endl;
            break;
        }
    }
    return 0;
}
