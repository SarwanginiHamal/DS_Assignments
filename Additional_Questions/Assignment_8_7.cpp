#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
};

struct DLLNode {
    int data;
    DLLNode* prev;
    DLLNode* next;
    DLLNode(int x) : data(x), prev(nullptr), next(nullptr) {}
};

void bstToDLL(TreeNode* root, DLLNode*& head, DLLNode*& tail) {
    if (!root) return;
    bstToDLL(root->left, head, tail);
    DLLNode* node = new DLLNode(root->data);
    if (!head) {
        head = tail = node;
    } else {
        tail->next = node;
        node->prev = tail;
        tail = node;
    }
    bstToDLL(root->right, head, tail);
}

DLLNode* mergeDLL(DLLNode* h1, DLLNode* h2) {
    DLLNode dummy(0);
    DLLNode* tail = &dummy;
    while (h1 && h2) {
        if (h1->data <= h2->data) {
            tail->next = h1;
            h1->prev = tail;
            h1 = h1->next;
        } else {
            tail->next = h2;
            h2->prev = tail;
            h2 = h2->next;
        }
        tail = tail->next;
    }
    DLLNode* rest = h1 ? h1 : h2;
    if (rest) {
        tail->next = rest;
        rest->prev = tail;
        while (tail->next) tail = tail->next;
    }
    DLLNode* head = dummy.next;
    if (head) head->prev = nullptr;
    return head;
}

void printDLL(DLLNode* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " <-> ";
        head = head->next;
    }
    cout << " <-> null\n";
}

int main() {
    TreeNode* t1 = new TreeNode(20);
    t1->left = new TreeNode(10);
    t1->right = new TreeNode(30);
    t1->left->right = new TreeNode(25);
    t1->right->right = new TreeNode(100);

    TreeNode* t2 = new TreeNode(50);
    t2->left = new TreeNode(5);
    t2->right = new TreeNode(70);

    DLLNode *h1 = nullptr, *tail1 = nullptr;
    DLLNode *h2 = nullptr, *tail2 = nullptr;

    bstToDLL(t1, h1, tail1);
    bstToDLL(t2, h2, tail2);

    DLLNode* merged = mergeDLL(h1, h2);
    printDLL(merged);
    return 0;
}
