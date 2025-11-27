#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void splitList(Node* head, Node** head1_ref, Node** head2_ref) {
    if (!head) return;
    Node *slow = head, *fast = head;
    while (fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }
    if (fast->next->next == head)
        fast = fast->next;
    *head1_ref = head;
    *head2_ref = slow->next;
    slow->next = *head1_ref;
    fast->next = *head2_ref;
}
void printList(Node* head) {
    if (!head) return;
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    Node* head = new Node(10);
    head->next = new Node(4);
    head->next->next = new Node(9);
    head->next->next->next = head; 
    Node *head1 = nullptr, *head2 = nullptr;
    splitList(head, &head1, &head2);
    cout << "First Circular List: ";
    printList(head1);
    cout << "Second Circular List: ";
    printList(head2);
    return 0;
}
