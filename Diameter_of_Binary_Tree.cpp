#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree(const vector<int>& nodes) {
    if (nodes.empty() || nodes[0] == -1) return NULL;
    
    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    
    while (!q.empty() && i < nodes.size()) {
        TreeNode* current = q.front();
        q.pop();
        
        if (nodes[i] != -1) {
            current->left = new TreeNode(nodes[i]);
            q.push(current->left);
        }
        i++;
        
        if (i < nodes.size() && nodes[i] != -1) {
            current->right = new TreeNode(nodes[i]);
            q.push(current->right);
        }
        i++;
    }
    
    return root;
}

int helper(TreeNode* root, int& ans) {
    if (root == NULL) return 0;
    int l = helper(root->left, ans);
    int r = helper(root->right, ans);
    ans = max(ans, l + r);
    return 1 + max(l, r);
}

int diameterOfBinaryTree(TreeNode* root) {
    int ans = 0;
    helper(root, ans);
    return ans;
}

int main() {
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;
    
    vector<int> nodes(n);
    cout << "Enter the nodes in level order (use -1 for NULL): ";
    for (int i = 0; i < n; ++i) {
        cin >> nodes[i];
    }
    
    TreeNode* root = buildTree(nodes);
    int diameter = diameterOfBinaryTree(root);
    
    cout << "Diameter of the binary tree is: " << diameter << endl;
    
    return 0;
}
