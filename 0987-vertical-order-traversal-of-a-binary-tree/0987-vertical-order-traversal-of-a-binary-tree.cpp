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
    map<int, map<int, multiset<int>>> nodes;
    void dfs(TreeNode* root, int x, int y){
        if(root == nullptr) return;
        nodes[x][y].insert(root -> val);
        dfs(root -> left, x - 1, y + 1);
        dfs(root -> right, x + 1, y + 1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result;
        dfs(root, 0, 0);
        for(auto& column : nodes){
            vector<int> temp;
            for(auto& row : column.second){
                for(int value : row.second){
                    temp.push_back(value);
                }
            }
            result.push_back(temp);
        }
        return result;
    }
};