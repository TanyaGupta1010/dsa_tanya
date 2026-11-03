/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr)
            return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        bool flag = true;
        while (!q.empty()) {
            int n = q.size();
            vector<int> level(n);
            for (int i = 0; i < n; i++) {
                TreeNode* temp = q.front();
                q.pop();
                int index = flag ? i : n - i - 1;
                level[index] = temp->val;
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
            ans.push_back(level);
            flag = !flag;
        }
        return ans;
    }
};