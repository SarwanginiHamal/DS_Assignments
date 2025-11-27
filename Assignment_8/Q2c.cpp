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
        if (value < node->data)
            node->left = insert(node->left, value);
        else
            node->right = insert(node->right, value);
        return node;
    }
    int findMin(Node* node) {
        if (node == nullptr) {
            cout << "Tree is empty!";
            return -1;
        }
        while (node->left != nullptr) {
            node = node->left;
        }
        return node->data;
    }
};

int main() {
    BST tree;
    int n, value;
    cout << "How many nodes do you want to insert? ";
    cin >> n;
    cout << "Enter " << n << " values:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        tree.root = tree.insert(tree.root, value);
    }
    cout << "\nMinimum element in BST = " << tree.findMin(tree.root);
    return 0;
}

