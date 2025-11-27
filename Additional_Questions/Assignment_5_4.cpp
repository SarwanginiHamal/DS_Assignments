#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}
Node* rotateLeft(Node* head, int k) {
    if (!head || !head->next || k == 0)
        return head;
    Node* temp = head;
    int length = 1;
    while (temp->next) {
        temp = temp->next;
        length++;
    }
    temp->next = head;
    k = k % length;
    int stepsToNewHead = length - k;
    Node* newTail = head;
    for (int i = 1; i < stepsToNewHead; i++)
        newTail = newTail->next;
    Node* newHead = newTail->next;
    newTail->next = nullptr; 
    return newHead;
}
int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    int k = 4;
    cout << "Original List: ";
    printList(head);
    head = rotateLeft(head, k);
    cout << "Rotated List: ";
    printList(head);
    return 0;
}
