#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node() {
        data = 0;
        next = nullptr;
    }
};

class CircularLinkedList {
private:
    Node* head;
public:
    CircularLinkedList() {
        head = nullptr;
    }

    void insertEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        if (!head) {
            head = newNode;
            newNode->next = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }

    void display() {
        if (!head) return;
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << head->data;
    }
};

int main() {
    CircularLinkedList cll;
    int arr[] = {20, 100, 40, 80, 60};
    for (int i = 0; i < 5; i++)
        cll.insertEnd(arr[i]);
    cll.display();
    return 0;
}
