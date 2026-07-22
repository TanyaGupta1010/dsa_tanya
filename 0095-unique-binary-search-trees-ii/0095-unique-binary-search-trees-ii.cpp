/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<TreeNode*> solve(int start, int end) {
        if (start > end)
            return {nullptr};

        vector<TreeNode*> ans;

        for (int root = start; root <= end; root++) {
            vector<TreeNode*> leftTrees = solve(start, root - 1);
            vector<TreeNode*> rightTrees = solve(root + 1, end);

            for (TreeNode* left : leftTrees) {
                for (TreeNode* right : rightTrees) {
                    TreeNode* node = new TreeNode(root);
                    node->left = left;
                    node->right = right;
                    ans.push_back(node);
                }
            }
        }

        return ans;
    }

    vector<TreeNode*> generateTrees(int n) {
        if (n == 0)
            return {};
        return solve(1, n);
    }
};