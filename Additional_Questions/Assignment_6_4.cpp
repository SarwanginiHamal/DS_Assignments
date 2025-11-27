#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node* random;
    Node(int x) : data(x), prev(nullptr), next(nullptr), random(nullptr) {}
};

void correctRandom(Node* head) {
    if (!head) return;
    Node* wrong = nullptr;
    Node* curr = head;
    while (curr) {
        if (curr->random && curr->random != curr->next) {
            wrong = curr;
            break;
        }
        curr = curr->next;
    }
    if (!wrong || !wrong->random) return;

    Node* target = wrong->random;
    Node* correct = target->prev;
    wrong->random = correct;
}

void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->random) cout << "(" << head->random->data << ")";
        if (head->next) cout << " <-> ";
        head = head->next;
    }
    cout << " <-> NULL\n";
}

int main() {
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);

    n1->next = n2;
    n2->prev = n1;
    n2->next = n3;
    n3->prev = n2;

    n2->random = n1;

    correctRandom(n1);
    printList(n1);

    return 0;
}
