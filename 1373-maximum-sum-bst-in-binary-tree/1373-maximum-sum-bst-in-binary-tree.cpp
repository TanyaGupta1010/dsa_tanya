/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    struct INFO{
        bool isbst;
        int minval;
        int maxval;
        int sum;
    };
    INFO solve(TreeNode* root){
        if(root == nullptr) return {true, INT_MAX, INT_MIN, 0};
        INFO left = solve(root -> left);
        INFO right = solve(root -> right);
        if(left.isbst && right.isbst && left.maxval < root -> val && root -> val < right.minval){
            int sum = left.sum + root -> val + right.sum;
            ans = max(ans, sum);
            int minval = min(root -> val, left.minval);
            int maxval = max(root -> val, right.maxval);
            return {true, minval, maxval, sum};
        }
        return {false, 0, 0, 0};
    }
    int maxSumBST(TreeNode* root) {
        solve(root);
        return ans;
    }
};