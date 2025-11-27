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
    Node* searchRecursive(Node* root, int key) {
        if (root == NULL || root->data == key)
            return root;
        if (key < root->data)
            return searchRecursive(root->left, key);
        else
            return searchRecursive(root->right, key);
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
    cout << "Enter value to search (recursive): ";
    cin >> key;
    Node* result = tree.searchRecursive(tree.root, key);
    if (result != NULL)
        cout << "Found!\n";
    else
        cout << "Not Found!\n";
    return 0;
}
