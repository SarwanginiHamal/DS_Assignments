#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

void insertEnd(Node*& head, int x) {
    Node* n = new Node(x);
    if (!head) {
        head = n;
        return;
    }
    Node* cur = head;
    while (cur->next) cur = cur->next;
    cur->next = n;
}

Node* buildList(const vector<int>& v) {
    Node* head = nullptr;
    for (int x : v) insertEnd(head, x);
    return head;
}

Node* unionList(Node* h1, Node* h2) {
    unordered_set<int> s;
    Node* res = nullptr;
    Node* cur;
    auto add = [&](int x) {
        if (s.insert(x).second) {
            if (!res) {
                res = new Node(x);
                cur = res;
            } else {
                cur->next = new Node(x);
                cur = cur->next;
            }
        }
    };
    while (h1) { add(h1->data); h1 = h1->next; }
    while (h2) { add(h2->data); h2 = h2->next; }
    return res;
}

Node* intersectionList(Node* h1, Node* h2) {
    unordered_set<int> s;
    while (h1) {
        s.insert(h1->data);
        h1 = h1->next;
    }
    Node* res = nullptr;
    Node* cur = nullptr;
    while (h2) {
        if (s.count(h2->data)) {
            if (!res) {
                res = new Node(h2->data);
                cur = res;
            } else {
                cur->next = new Node(h2->data);
                cur = cur->next;
            }
            s.erase(h2->data);
        }
        h2 = h2->next;
    }
    return res;
}

void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " -> ";
