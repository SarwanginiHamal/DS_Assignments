#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void removeLoop(Node* head) {
    if (!head || !head->next) return;
    Node* slow = head;
    Node* fast = head;
    bool loopExists = false;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            loopExists = true;
            break;
        }
    }
    if (!loopExists) return;
    slow = head;
    Node* prev = nullptr; 
    while (slow != fast) {
        prev = fast;
        slow = slow->next;
        fast = fast->next;
    }
    prev->next = nullptr;
}
void insertNode(Node*& head, int val) {
    if (!head) {
        head = new Node(val);
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = new Node(val);
}
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next) cout << "->";
        temp = temp->next;
    }
    cout << endl;
}
int main() {
    Node* head = nullptr;
    insertNode(head, 1);
    insertNode(head, 7);
    insertNode(head, 3);
    insertNode(head, 6);
    head->next->next->next->next = head->next;
    removeLoop(head);
    cout << "List after removing loop: ";
    printList(head);
    return 0;
}
