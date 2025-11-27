#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};
Node* reverseKGroup(Node* head, int k) {
    Node* curr = head;
    Node* prev = nullptr;
    Node* next = nullptr;
    int count = 0;
    Node* temp = head;
    for (int i = 0; i < k; i++) {
        if (!temp) return head;  
        temp = temp->next;
    }
    while (curr != nullptr && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    if (next != nullptr) {
        head->next = reverseKGroup(next, k);
    }
    return prev;
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
void insertNode(Node*& head, int val) {
    if (!head) {
        head = new Node(val);
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = new Node(val);
}
int main() {
    Node* head = nullptr;
    int n, val, K;
    cout << "Enter the number of elements in the linked list: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        insertNode(head, val);
    }
    cout << "Enter the value of K: ";
    cin >> K;
    cout << "Original List: ";
    printList(head);
    head = reverseKGroup(head, K);
    cout << "Reversed in groups of " << K << ": ";
    printList(head);
    return 0;
}
