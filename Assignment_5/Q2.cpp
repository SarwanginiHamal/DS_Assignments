#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
    Node* head;
public:
    LinkedList() : head(nullptr) {}

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    int deleteAllOccurrences(int key) {
        int count = 0;
        while (head && head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
            count++;
        }
        Node* curr = head;
        while (curr && curr->next) {
            if (curr->next->data == key) {
                Node* temp = curr->next;
                curr->next = temp->next;
                delete temp;
                count++;
            } else {
                curr = curr->next;
            }
        }
        return count;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data;
            if (temp->next) cout << "->";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    int arr[] = {1,2,1,2,1,3,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i < n; i++) list.insertAtEnd(arr[i]);
    
    int key = 1;
    int count = list.deleteAllOccurrences(key);
    cout << "Count: " << count << " , Updated Linked List: ";
    list.display(); 
    return 0;
}
