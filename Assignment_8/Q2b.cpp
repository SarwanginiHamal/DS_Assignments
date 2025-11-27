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
        else
            root->right = insert(root->right, value);
        return root;
    }
    Node* findMaxRecursive(Node* root) {
        if (root == NULL)
            return NULL;
        if (root->right == NULL)
            return root;
        return findMaxRecursive(root->right);
    }
};

int main() {
    BST tree;
    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter values:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        tree.root = tree.insert(tree.root, value);
    }

    Node* maxNode = tree.findMaxRecursive(tree.root);

    if (maxNode != NULL)
        cout << "Maximum element (recursive) = " << maxNode->data << endl;
    else
        cout << "Tree is empty!\n";
    return 0;
}
