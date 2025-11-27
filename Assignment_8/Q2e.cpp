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
    Node* search(Node* node, int key) {
        if (node == nullptr || node->data == key)
            return node;
        if (key < node->data)
            return search(node->left, key);
        else
            return search(node->right, key);
    }
    Node* findMax(Node* node) {
        while (node && node->right != nullptr)
            node = node->right;
        return node;
    }
    Node* inorderPredecessor(Node* root, Node* target) {
        if (target == nullptr) return nullptr;
        if (target->left != nullptr) {
            return findMax(target->left);
        }
        Node* predecessor = nullptr;
        Node* current = root;
        while (current != nullptr) {
            if (target->data > current->data) {
                predecessor = current;
                current = current->right;
            }
            else if (target->data < current->data) {
                current = current->left;
            }
            else
                break;
        }
        return predecessor;
    }
};

int main() {
    BST tree;
    int n, value, key;
    cout << "How many nodes do you want to insert? ";
    cin >> n;
    cout << "Enter " << n << " values:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        tree.root = tree.insert(tree.root, value);
    }
    cout << "\nEnter the key to find inorder predecessor: ";
    cin >> key;
    Node* target = tree.search(tree.root, key);
    if (target == nullptr) {
        cout << "Key not found in BST.";
        return 0;
    }
    Node* predecessor = tree.inorderPredecessor(tree.root, target);
    if (predecessor == nullptr)
        cout << "\nNo inorder predecessor found (key is the smallest element).";
    else
        cout << "\nInorder Predecessor of " << key << " = " << predecessor->data;
    return 0;
}
