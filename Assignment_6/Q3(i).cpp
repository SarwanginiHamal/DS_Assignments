#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
    Node() {
        data = 0;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
public:
    DoublyLinkedList() {
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
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    int size() {
        int count = 0;
        Node* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

int main() {
    DoublyLinkedList dll;
    dll.insertEnd(25);
    dll.insertEnd(35);
    dll.insertEnd(45);
    dll.insertEnd(55);

    cout << "Size of Doubly Linked List: " << dll.size() << endl;
    return 0;
}
