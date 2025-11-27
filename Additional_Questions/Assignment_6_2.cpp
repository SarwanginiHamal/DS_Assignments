#include <iostream>
using namespace std;

struct CLLNode {
    int data;
    CLLNode* next;
    CLLNode(int val) : data(val), next(nullptr) {}
};

struct DLLNode {
    int data;
    DLLNode* next;
    DLLNode* prev;
    DLLNode(int val) : data(val), next(nullptr), prev(nullptr) {}
};

int parity(int n) {
    int count = 0;
    while (n) {
        count += (n & 1);
        n >>= 1;
    }
    return count;
}

CLLNode* removeEvenParityCLL(CLLNode* head) {
    if (!head) return nullptr;
    CLLNode *curr = head, *prev = nullptr, *start = head;
    do {
        if (parity(curr->data) % 2 == 0) {
            if (curr == head) {
                CLLNode* temp = head;
                while (temp->next != head) temp = temp->next;
                if (head->next == head) return nullptr;
                temp->next = head->next;
                head = head->next;
                delete curr;
                curr = head;
                start = head;
                prev = temp;
            } else {
                prev->next = curr->next;
                CLLNode* temp = curr;
                curr = curr->next;
                delete temp;
            }
        } else {
            prev = curr;
            curr = curr->next;
        }
    } while (curr != start);
    return head;
}

DLLNode* removeEvenParityDLL(DLLNode* head) {
    DLLNode* curr = head;
    while (curr) {
        if (parity(curr->data) % 2 == 0) {
            if (curr->prev) curr->prev->next = curr->next;
            else head = curr->next;
            if (curr->next) curr->next->prev = curr->prev;
            DLLNode* temp = curr;
            curr = curr->next;
            delete temp;
        } else {
            curr = curr->next;
        }
    }
    return head;
}

void printCLL(CLLNode* head) {
    if (!head) return;
    CLLNode* temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "HEAD\n";
}

void printDLL(DLLNode* head) {
    DLLNode* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next) cout << " <=> ";
        temp = temp->next;
    }
    cout << "\n";
}

int main() {
    CLLNode* cll = new CLLNode(9);
    cll->next = new CLLNode(11);
    cll->next->next = new CLLNode(34);
    cll->next->next->next = new CLLNode(6);
    cll->next->next->next->next = new CLLNode(13);
    cll->next->next->next->next->next = new CLLNode(21);
    cll->next->next->next->next->next->next = cll;

    DLLNode* dll = new DLLNode(18);
    dll->next = new DLLNode(15);
    dll->next->prev = dll;
    dll->next->next = new DLLNode(8);
    dll->next->next->prev = dll->next;
    dll->next->next->next = new DLLNode(9);
    dll->next->next->next->prev = dll->next->next;
    dll->next->next->next->next = new DLLNode(14);
    dll->next->next->next->next->prev = dll->next->next->next;

    cll = removeEvenParityCLL(cll);
    dll = removeEvenParityDLL(dll);

    printCLL(cll);
    printDLL(dll);

    return 0;
}
