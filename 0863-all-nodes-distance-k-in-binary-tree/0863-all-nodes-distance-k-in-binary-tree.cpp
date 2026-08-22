/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markparents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp -> left){
                parent[temp -> left] = temp;
                q.push(temp -> left);
            }
            if(temp -> right){
                parent[temp -> right] = temp;
                q.push(temp -> right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        markparents(root, parent);
        queue<TreeNode*> q;
        q.push(target);
        unordered_map<TreeNode*, bool> visited;
        visited[target] = true;
        int distance = 0;\
        while(!q.empty()){
            int size = q.size();
            if(distance == k) break;
            while(size --){
                TreeNode* temp = q.front();
                q.pop();
                if(temp -> left && !visited[temp -> left]){
                    visited[temp -> left] = true;
                    q.push(temp -> left);
                }
                if(temp -> right && !visited[temp -> right]){
                    visited[temp -> right] = true;
                    q.push(temp -> right);
                }
                if(parent[temp] && !visited[parent[temp]]){
                    visited[parent[temp]] = true;
                    q.push(parent[temp]); 
                }
            }
            distance ++;
        }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front() -> val);
            q.pop();
        }
        return ans;
    }
};