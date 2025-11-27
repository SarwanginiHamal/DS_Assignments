#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int maxDepth(TreeNode* root) {
    if (!root) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

TreeNode* buildTree(const vector<int>& a) {
    if (a.empty() || a[0] == -1) return nullptr;
    int n = a.size();
    TreeNode* root = new TreeNode(a[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < n) {
        TreeNode* cur = q.front();
        q.pop();
        if (i < n && a[i] != -1) {
            cur->left = new TreeNode(a[i]);
            q.push(cur->left);
        }
        i++;
        if (i < n && a[i] != -1) {
            cur->right = new TreeNode(a[i]);
            q.push(cur->right);
        }
        i++;
    }
    return root;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        TreeNode* root = buildTree(a);
        cout << maxDepth(root) << "\n";
    }
    return 0;
}
