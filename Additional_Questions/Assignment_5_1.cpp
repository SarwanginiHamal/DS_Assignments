#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    if (!headA || !headB) return nullptr;
    ListNode* ptrA = headA;
    ListNode* ptrB = headB;
    while (ptrA != ptrB) {
        ptrA = ptrA ? ptrA->next : headB;
        ptrB = ptrB ? ptrB->next : headA;
    }
    return ptrA;
}
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}
int main() {
    ListNode* headA = new ListNode(4);
    headA->next = new ListNode(1);
    ListNode* intersection = new ListNode(8);
    headA->next->next = intersection;
    intersection->next = new ListNode(5);
    ListNode* headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = intersection; 
    cout << "List A: ";
    printList(headA);
    cout << "List B: ";
    printList(headB);
    ListNode* intersectNode = getIntersectionNode(headA, headB);
    if (intersectNode) {
        cout << "Intersected at " << intersectNode->val << endl;
    } else {
        cout << "No intersection" << endl;
    }
    return 0;
}
