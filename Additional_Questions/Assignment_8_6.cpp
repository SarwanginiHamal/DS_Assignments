#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildRec(vector<int>& inorder, int inL, int inR,
                   vector<int>& postorder, int postL, int postR,
                   unordered_map<int,int>& pos) {
    if (inL > inR || postL > postR) return nullptr;
    int rootVal = postorder[postR];
    TreeNode* root = new TreeNode(rootVal);
    int k = pos[rootVal];
    int leftSize = k - inL;
    root->left = buildRec(inorder, inL, k - 1,
                          postorder, postL, postL + leftSize - 1, pos);
    root->right = buildRec(inorder, k + 1, inR,
                           postorder, postL + leftSize, postR - 1, pos);
    return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int n = inorder.size();
    unordered_map<int,int> pos;
    for (int i = 0; i < n; ++i) pos[inorder[i]] = i;
    return buildRec(inorder, 0, n - 1, postorder, 0, n - 1, pos);
}

void preorderPrint(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    preorderPrint(root->left);
    preorderPrint(root->right);
}

int main() {
    int n;
    cin >> n;
    vector<int> inorder(n), postorder(n);
    for (int i = 0; i < n; ++i) cin >> inorder[i];
    for (int i = 0; i < n; ++i) cin >> postorder[i];
    TreeNode* root = buildTree(inorder, postorder);
    preorderPrint(root);
    return 0;
}
