#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class DoublyList {
public:
    Node* head;
    DoublyList() {
        head = NULL;
    }

    void insertBeg(int val) {
        Node* n = new Node(val);
        if (head == NULL) {
            head = n;
            return;
        }
        n->next = head;
        head->prev = n;
        head = n;
    }

    void insertEnd(int val) {
        Node* n = new Node(val);
        if (head == NULL) {
            head = n;
            return;
        }
        Node* t = head;
        while (t->next != NULL)
            t = t->next;
        t->next = n;
        n->prev = t;
    }

    void insertAfter(int key, int val) {
        Node* t = head;
        while (t != NULL && t->data != key)
            t = t->next;
        if (t == NULL) {
            cout << "Node not found\n";
            return;
        }
        Node* n = new Node(val);
        n->next = t->next;
        n->prev = t;
        if (t->next)
            t->next->prev = n;
        t->next = n;
    }

    void insertBefore(int key, int val) {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }
        Node* t = head;
        while (t != NULL && t->data != key)
            t = t->next;
        if (t == NULL) {
            cout << "Node not found\n";
            return;
        }
        Node* n = new Node(val);
        n->next = t;
        n->prev = t->prev;
        if (t->prev)
            t->prev->next = n;
        else
            head = n;
        t->prev = n;
    }

    void delNode(int key) {
        if (head == NULL) {
            cout << "The list is empty\n";
            return;
        }
        Node* t = head;
        while (t != NULL && t->data != key)
            t = t->next;
        if (t == NULL) {
            cout << "Node not found\n";
            return;
        }
        if (t->prev)
            t->prev->next = t->next;
        else
            head = t->next;
        if (t->next)
            t->next->prev = t->prev;
        delete t;
        cout << "Deleted\n";
    }

    void search(int key) {
        Node* t = head;
        int pos = 1;
        while (t != NULL) {
            if (t->data == key) {
                cout << "Found at position " << pos << "\n";
                return;
            }
            t = t->next;
            pos++;
        }
        cout << "Not found\n";
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }
        Node* t = head;
        while (t != NULL) {
            cout << t->data << " ";
            t = t->next;
        }
        cout << "\n";
    }
};

class CircularList {
public:
    Node* head;
    CircularList() {
        head = NULL;
    }

    void insertEnd(int val) {
        Node* n = new Node(val);
        if (head == NULL) {
            head = n;
            n->next = head;
            return;
        }
        Node* t = head;
        while (t->next != head)
            t = t->next;
        t->next = n;
        n->next = head;
    }

    void display() {
        if (head == NULL) {
            cout << "The list is empty\n";
            return;
        }
        Node* t = head;
        do {
            cout << t->data << " ";
            t = t->next;
        } while (t != head);
        cout << "\n";
    }
};

int main() {
    DoublyList dl;
    CircularList cl;
    int ch, val, key;

    while (true) {
        cout << "\n1.Insert at Beg(DLL)"
             << "\n2.Insert at End(DLL)"
             << "\n3.Insert After(DLL)"
             << "\n4.Insert Before(DLL)"
             << "\n5.Delete(DLL)"
             << "\n6.Search(DLL)"
             << "\n7.Display(DLL)"
             << "\n8.Insert Circular"
             << "\n9.Display circular"
             << "\n10.Exit\n";
        cout << "Enter choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                dl.insertBeg(val);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> val;
                dl.insertEnd(val);
                break;
            case 3:
                cout << "Enter key (after which to insert): ";
                cin >> key;
                cout << "Enter value: ";
                cin >> val;
                dl.insertAfter(key, val);
                break;
            case 4:
                cout << "Enter key (before which to insert): ";
                cin >> key;
                cout << "Enter value: ";
                cin >> val;
                dl.insertBefore(key, val);
                break;
            case 5:
                cout << "Enter value to delete: ";
                cin >> key;
                dl.delNode(key);
                break;
            case 6:
                cout << "Enter value to search: ";
                cin >> key;
                dl.search(key);
                break;
            case 7:
                dl.display();
                break;
            case 8:
                cout << "Enter value: ";
                cin >> val;
                cl.insertEnd(val);
                break;
            case 9:
                cl.display();
                break;
            case 10:
                return 0;
            default:
                cout << "Invalid Choice\n";
        }
    }
    return 0;
}
