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
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int currdiameter = heightofbinarytree(root -> left) + heightofbinarytree(root -> right);
        int leftdiameter = diameterOfBinaryTree(root -> left);
        int rightdiameter = diameterOfBinaryTree(root -> right);
        return max(currdiameter,  max (leftdiameter, rightdiameter));
    }
    int heightofbinarytree(TreeNode* root){
        if(!root) return 0;
        int leftheight = heightofbinarytree(root -> left);
        int rightheight = heightofbinarytree(root -> right);
        return max(leftheight, rightheight) + 1;
    }
};