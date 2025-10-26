#include <iostream>
using namespace std;

#define SIZE 5

class CircularQueue {
    int items[SIZE], front, rear;
public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return (front == 0 && rear == SIZE - 1) || (front == rear + 1);
    }

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(int element) {
        if(isFull()) {
            cout << "Queue is full!" << endl;
            return;
        }
        if(isEmpty()) {
            front = rear = 0;
        } else if(rear == SIZE - 1 && front != 0) {
            rear = 0;
        } else {
            rear++;
        }
        items[rear] = element;
        cout << "Enqueued: " << element << endl;
    }

    void dequeue() {
        if(isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Dequeued: " << items[front] << endl;
        if(front == rear) { 
            front = rear = -1;
        } else if(front == SIZE - 1) {
            front = 0;
        } else {
            front++;
        }
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
            return;
        }
        cout << "Queue elements: ";
        if(rear >= front) {
            for(int i = front; i <= rear; i++)
                cout << items[i] << " ";
        } else {
            for(int i = front; i < SIZE; i++)
                cout << items[i] << " ";
            for(int i = 0; i <= rear; i++)
                cout << items[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    CircularQueue cq;
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
                cq.enqueue(value);
                break;
            case 2:
                cq.dequeue();
                break;
            case 3:
                cout << (cq.isEmpty() ? "Queue is empty" : "Queue is not empty") << endl;
                break;
            case 4:
                cout << (cq.isFull() ? "Queue is full" : "Queue is not full") << endl;
                break;
            case 5:
                cq.display();
                break;
            case 6:
                cq.peek();
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
