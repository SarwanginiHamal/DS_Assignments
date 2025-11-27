#include <iostream>
#include <climits>
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

class BinaryTree {
public:
    Node* root;
    BinaryTree() {
        root = nullptr;
    }
    Node* insert(Node* node, int value) {
        if (node == nullptr)
            return new Node(value);
        if (value < node->data)
            node->left = insert(node->left, value);
        else if (value > node->data)
            node->right = insert(node->right, value);
        return node;
    }
    bool isBST(Node* node, int minValue = INT_MIN, int maxValue = INT_MAX) {
        if (node == nullptr)
            return true;
        if (node->data <= minValue || node->data >= maxValue)
            return false;
        return isBST(node->left, minValue, node->data) &&
               isBST(node->right, node->data, maxValue);
    }
    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
};

int main() {
    BinaryTree tree;
    int n, value;
    cout << "How many nodes do you want to insert? ";
    cin >> n;
    cout << "Enter " << n << " values:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        tree.root = tree.insert(tree.root, value);
    }
    cout << "\nInorder Traversal of Tree: ";
    tree.inorder(tree.root);
    if (tree.isBST(tree.root))
        cout << "\n\nThe tree IS a BST.";
    else
        cout << "\n\nThe tree is NOT a BST.";
    return 0;
}
