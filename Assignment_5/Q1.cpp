#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
    Node* head;
public:
    LinkedList() : head(nullptr) {}

    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        cout << "Inserted " << val << " at the beginning.\n";
    }
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            cout << "Inserted " << val << " at the end.\n";
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
        cout << "Inserted " << val << " at the end.\n";
    }

    void insertBefore(int key, int val) {
        if (!head) { cout << "List is empty." << endl; return; }
        if (head->data == key) {
            insertAtBeginning(val);
            return;
        }
        Node* curr = head, *prev = nullptr;
        while (curr && curr->data != key) {
            prev = curr;
            curr = curr->next;
        }
        if (!curr) {
            cout << "Node with value " << key << " not found.\n";
            return;
        }
        Node* newNode = new Node(val);
        prev->next = newNode;
        newNode->next = curr;
        cout << "Inserted " << val << " before " << key << endl;
    }
    void insertAfter(int key, int val) {
        Node* temp = head;
        while (temp && temp->data != key) temp = temp->next;
        if (!temp) {
            cout << "Node with value " << key << " not found.\n";
            return;
        }
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Inserted " << val << " after " << key << endl;
    }

    void deleteFromBeginning() {
        if (!head) { cout << "List is empty." << endl; return; }
        Node* temp = head;
        head = head->next;
        cout << "Deleted " << temp->data << " from beginning.\n";
        delete temp;
    }

    void deleteFromEnd() {
        if (!head) { cout << "List is empty." << endl; return; }
        if (!head->next) {
            cout << "Deleted " << head->data << " from end.\n";
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next) temp = temp->next;
        cout << "Deleted " << temp->next->data << " from end.\n";
        delete temp->next;
        temp->next = nullptr;
    }

    void deleteNode(int key) {
        if (!head) { cout << "List is empty." << endl; return; }
        if (head->data == key) {
            Node* temp = head;
            head = head->next;
            cout << "Deleted node with value " << key << endl;
            delete temp;
            return;
        }
        Node* curr = head, *prev = nullptr;
        while (curr && curr->data != key) {
            prev = curr;
            curr = curr->next;
        }
        if (!curr) {
            cout << "Node with value " << key << " not found.\n";
            return;
        }
        prev->next = curr->next;
        cout << "Deleted node with value " << key << endl;
        delete curr;
    }

    void searchNode(int key) {
        Node* temp = head;
        int pos = 1;
        while (temp) {
            if (temp->data == key) {
                cout << "Node with value " << key << " found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Node with value " << key << " not found.\n";
    }

    void display() {
        Node* temp = head;
        cout << "List: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    int choice, val, key;
    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at beginning\n2. Insert at end\n3. Insert before a value\n4. Insert after a value\n";
        cout << "5. Delete from beginning\n6. Delete from end\n7. Delete a specific node\n8. Search for a node\n9. Display all\n10. Exit\n";
        cout << "Enter your choice: "; cin >> choice;
        switch(choice) {
            case 1:
                cout << "Enter value: "; cin >> val;
                list.insertAtBeginning(val); break;
            case 2:
                cout << "Enter value: "; cin >> val;
                list.insertAtEnd(val); break;
            case 3:
                cout << "Enter value before which to insert: "; cin >> key;
                cout << "Enter value to insert: "; cin >> val;
                list.insertBefore(key, val); break;
            case 4:
                cout << "Enter value after which to insert: "; cin >> key;
                cout << "Enter value to insert: "; cin >> val;
                list.insertAfter(key, val); break;
            case 5:
                list.deleteFromBeginning(); break;
            case 6:
                list.deleteFromEnd(); break;
            case 7:
                cout << "Enter value to delete: "; cin >> key;
                list.deleteNode(key); break;
            case 8:
                cout << "Enter value to search: "; cin >> key;
                list.searchNode(key); break;
            case 9:
                list.display(); break;
            case 10:
                cout << "Exiting program.\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 10);
    return 0;
}

