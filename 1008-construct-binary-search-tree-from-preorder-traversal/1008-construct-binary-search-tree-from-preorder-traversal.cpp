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
    int index = 0;
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return build(preorder, INT_MIN, INT_MAX);
    }
    TreeNode* build(vector<int>& preorder, int minval, int maxval){
        if(index >= preorder.size()) return nullptr;
        int val = preorder[index];
        if(val <= minval || val >= maxval) return nullptr;
        index++;
        TreeNode* root = new TreeNode(val);
        root -> left = build(preorder, minval, val);
        root -> right = build(preorder, val, maxval);
        return root;
    }
};