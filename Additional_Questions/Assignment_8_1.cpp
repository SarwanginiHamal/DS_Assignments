#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int sumOfLeftLeaves(TreeNode* root, bool isLeft = false) {
    if (!root) return 0;
    if (!root->left && !root->right) return isLeft ? root->val : 0;
    return sumOfLeftLeaves(root->left, true) + sumOfLeftLeaves(root->right, false);
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << sumOfLeftLeaves(root) << endl;
    return 0;
}
