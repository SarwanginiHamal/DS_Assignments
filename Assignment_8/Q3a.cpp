#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

class BST {
public:
    Node* root;

    BST() {
        root = nullptr;
    }
    Node* insert(Node* node, int value) {
        if (node == nullptr)
            return new Node(value);

        if (value < node->data) {
            node->left = insert(node->left, value);
        }
        else if (value > node->data) {
            node->right = insert(node->right, value);
        }
        else {
            cout << "Duplicate value " << value << " not allowed!\n";
        }
        return node;
    }
    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
};

int main() {
    BST tree;
    int n, value;
    cout << "How many values do you want to insert? ";
    cin >> n;
    cout << "Enter " << n << " values:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        tree.root = tree.insert(tree.root, value);
    }
    cout << "\nBST (Inorder Traversal): ";
    tree.inorder(tree.root);
    return 0;
}
