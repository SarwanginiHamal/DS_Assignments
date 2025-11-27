#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildTreeRec(vector<int>& preorder, int preL, int preR,
                       vector<int>& inorder, int inL, int inR,
                       unordered_map<int,int>& pos) {
    if (preL > preR || inL > inR) return nullptr;
    int rootVal = preorder[preL];
    TreeNode* root = new TreeNode(rootVal);
    int k = pos[rootVal];
    int leftSize = k - inL;
    root->left = buildTreeRec(preorder, preL + 1, preL + leftSize,
                              inorder, inL, k - 1, pos);
    root->right = buildTreeRec(preorder, preL + leftSize + 1, preR,
                               inorder, k + 1, inR, pos);
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int n = preorder.size();
    unordered_map<int,int> pos;
    for (int i = 0; i < n; ++i) pos[inorder[i]] = i;
    return buildTreeRec(preorder, 0, n - 1, inorder, 0, n - 1, pos);
}

void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    int n;
    cin >> n;
    vector<int> preorder(n), inorder(n);
    for (int i = 0; i < n; ++i) cin >> preorder[i];
    for (int i = 0; i < n; ++i) cin >> inorder[i];
    TreeNode* root = buildTree(preorder, inorder);
    printInorder(root);
    return 0;
}
