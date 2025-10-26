#include <iostream>
using namespace std;

#define SIZE 5

class Queue {
    int items[SIZE], front, rear;
public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return rear == SIZE - 1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    void enqueue(int element) {
        if(isFull()) {
            cout << "Queue is full!" << endl;
            return;
        }
        if(front == -1) front = 0;
        items[++rear] = element;
        cout << "Enqueued: " << element << endl;
    }

    void dequeue() {
        if(isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Dequeued: " << items[front++] << endl;
    }

    void peek() {
        if(isEmpty()) {
            cout << "Queue is empty!" << endl;
        } else {
            cout << "Front element: " << items[front] << endl;
        }
    }

    void display() {
        if(isEmpty()) {
            cout << "Queue is empty!" << endl;
        } else {
            cout << "Queue elements: ";
            for(int i = front; i <= rear; i++)
                cout << items[i] << " ";
            cout << endl;
        }
    }
};

int main() {
    Queue q;
    int choice, value;
    do {
        cout << "\nMenu:\n";
        cout << "1. Enqueue\n2. Dequeue\n3. isEmpty\n4. isFull\n5. Display\n6. Peek\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                cout << (q.isEmpty() ? "Queue is empty" : "Queue is not empty") << endl;
                break;
            case 4:
                cout << (q.isFull() ? "Queue is full" : "Queue is not full") << endl;
                break;
            case 5:
                q.display();
                break;
            case 6:
                q.peek();
                break;
            case 7:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while(choice != 7);

    return 0;
}

