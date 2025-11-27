#include <iostream>
using namespace std;

struct Node {
    int coeff;
    int pow;
    Node* next;
    Node(int c, int p) : coeff(c), pow(p), next(nullptr) {}
};

void append(Node*& head, int coeff, int pow) {
    Node* newNode = new Node(coeff, pow);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}
Node* addPolynomials(Node* poly1, Node* poly2) {
    Node* result = nullptr;
    Node* p1 = poly1;
    Node* p2 = poly2;
    while (p1 && p2) {
        if (p1->pow > p2->pow) {
            append(result, p1->coeff, p1->pow);
            p1 = p1->next;
        } else if (p1->pow < p2->pow) {
            append(result, p2->coeff, p2->pow);
            p2 = p2->next;
        } else {
            append(result, p1->coeff + p2->coeff, p1->pow);
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    while (p1) {
        append(result, p1->coeff, p1->pow);
        p1 = p1->next;
    }
    while (p2) {
        append(result, p2->coeff, p2->pow);
        p2 = p2->next;
    }
    return result;
}

void printPolynomial(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << "[" << temp->coeff << ", " << temp->pow << "]";
        if (temp->next) cout << " -> ";
        temp = temp->next;
    }
    cout << " -> NULL" << endl;
}

int main() {
    Node* poly1 = nullptr;
    Node* poly2 = nullptr;
    append(poly1, 5, 2);
    append(poly1, 4, 1);
    append(poly1, 2, 0);
    append(poly2, 5, 1);
    append(poly2, 5, 0);
    cout << "Polynomial 1: ";
    printPolynomial(poly1);
    cout << "Polynomial 2: ";
    printPolynomial(poly2);
    Node* sum = addPolynomials(poly1, poly2);
    cout << "Sum: ";
    printPolynomial(sum);
    return 0;
}
