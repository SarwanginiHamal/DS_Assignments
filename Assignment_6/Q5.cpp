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

class LinkedList {
private:
    Node* head;
public:
    LinkedList() {
        head = nullptr;
    }

    void insertEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr && temp->next != head)
            temp = temp->next;
        temp->next = newNode;
    }

    void makeCircular() {
        if (!head) return;
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = head;
    }

    void checkCircular() {
        if (!head) {
            cout << "List is empty, not circular." << endl;
            return;
        }
        Node* temp = head->next;
        while (temp != nullptr && temp != head)
            temp = temp->next;
        if (temp == head)
            cout << "Linked list is Circular." << endl;
        else
            cout << "Linked list is NOT Circular." << endl;
    }
};

int main() {
    LinkedList llist;
    llist.insertEnd(10);
    llist.insertEnd(20);
    llist.insertEnd(30);
    llist.checkCircular();
    return 0;
}
