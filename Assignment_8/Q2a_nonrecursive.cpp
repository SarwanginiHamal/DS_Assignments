#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) {
        data = value;
        left = right = NULL;
    }
};
class BST {
public:
    Node* root;
    BST() {
      root = NULL; 
    }
    Node* insert(Node* root, int value) {
        if (root == NULL)
            return new Node(value);
        if (value < root->data)
            root->left = insert(root->left, value);
        else if (value > root->data)
            root->right = insert(root->right, value);
        return root;
    }
    Node* searchNonRecursive(Node* root, int key) {
        Node* current = root;
        while (current != NULL) {
            if (current->data == key)
                return current;
            if (key < current->data)
                current = current->left;
            else
                current = current->right;
        }
        return NULL; 
    }
};

int main() {
    BST tree;
    int n, value, key;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter values:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        tree.root = tree.insert(tree.root, value);
    }
    cout << "Enter value to search (non-recursive): ";
    cin >> key;
    Node* result = tree.searchNonRecursive(tree.root, key);
    if (result != NULL)
        cout << "Found!\n";
    else
        cout << "Not Found!\n";
    return 0;
}
