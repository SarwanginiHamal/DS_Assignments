#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};
bool hasLoop(Node* head) {
    unordered_set<Node*> nodesSeen;
    Node* current = head;
    while (current != nullptr) {
        if (nodesSeen.find(current) != nodesSeen.end())
            return true;
        nodesSeen.insert(current);
        current = current->next;
    }
    return false; 
}

int main() {
    Node* head = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    head->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n2; 
    if (hasLoop(head))
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 0;
}
