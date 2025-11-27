#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int x) : data(x), next(nullptr), prev(nullptr) {}
};

Node* reverseInGroups(Node* head, int k) {
    if (!head || k <= 1) return head;
    Node* curr = head;
    Node* newHead = nullptr;
    Node* groupPrevTail = nullptr;

    while (curr) {
        Node* groupHead = curr;
        Node* temp = curr;
        int count = 0;
        while (temp && count < k) {
            temp = temp->next;
            count++;
        }
        if (count < k && !temp) {
            Node* node = groupHead;
            while (node->next) node = node->next;
            if (groupPrevTail) {
                groupPrevTail->next = node;
                node->prev = groupPrevTail;
                return newHead;
            } else {
                return head;
            }
        }
        Node* prev = nullptr;
        Node* next = nullptr;
        int c = 0;
        while (curr && c < k) {
            next = curr->next;
            curr->next = prev;
            curr->prev = next;
            prev = curr;
            curr = next;
            c++;
        }
        if (!newHead) newHead = prev;
        if (groupPrevTail) {
            groupPrevTail->next = prev;
            prev->prev = groupPrevTail;
        }
        groupPrevTail = groupHead;
    }
    return newHead;
}

void pushFront(Node*& head, int data) {
    Node* node = new Node(data);
    node->next = head;
    if (head) head->prev = node;
    head = node;
}

void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " <-> ";
        head = head->next;
    }
    cout << " <-> NULL\n";
}

int main() {
    Node* head = nullptr;
    for (int i = 6; i >= 1; --i) pushFront(head, i);

    int k1 = 2;
    Node* res1 = reverseInGroups(head, k1);
    printList(res1);

    Node* head2 = nullptr;
    for (int i = 6; i >= 1; --i) pushFront(head2, i);
    int k2 = 4;
    Node* res2 = reverseInGroups(head2, k2);
    printList(res2);

    return 0;
}
