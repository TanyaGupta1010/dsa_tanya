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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        unordered_map<int, int> map;

        for(int i = 0; i < inorder.size(); i++) {
            map[inorder[i]] = i;
        }

        return solve(preorder, 0, preorder.size() - 1,
                     inorder, 0, inorder.size() - 1, map);
    }

    TreeNode* solve(vector<int>& preorder, int ps, int pe,
                    vector<int>& inorder, int is, int ie,
                    unordered_map<int, int>& map) {

        if(ps > pe || is > ie)
            return nullptr;

        int rootvalue = preorder[ps];

        TreeNode* root = new TreeNode(rootvalue);

        int rootindex = map[rootvalue];

        int leftsize = rootindex - is;

        root->left = solve(preorder,
                           ps + 1,
                           ps + leftsize,
                           inorder,
                           is,
                           rootindex - 1,
                           map);

        root->right = solve(preorder,
                            ps + leftsize + 1,
                            pe,
                            inorder,
                            rootindex + 1,
                            ie,
                            map);

        return root;
    }
};