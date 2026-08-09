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
class FindElements {
public:
    unordered_set<int> s;
    queue<TreeNode*> q;
    FindElements(TreeNode* root) {
        root -> val = 0;
        s.insert(0);
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp -> left) {
                temp -> left -> val = 2 * temp -> val + 1;
                s.insert(temp -> left -> val);
                q.push(temp -> left);
            }
            if(temp -> right){
                temp -> right -> val = 2 * temp -> val + 2;
                s.insert(temp -> right -> val);
                q.push(temp -> right);
            }
        }
    }
    
    bool find(int target) {
        return s.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */