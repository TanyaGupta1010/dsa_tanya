/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Serialize
    string serialize(TreeNode* root) {
        if(root == nullptr)
            return "#,";

        return to_string(root->val) + "," +
               serialize(root->left) +
               serialize(root->right);
    }

    // Deserialize
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return build(ss);
    }

    TreeNode* build(stringstream& ss) {
        string value;

        getline(ss, value, ',');

        if(value == "#")
            return nullptr;

        TreeNode* root = new TreeNode(stoi(value));

        root->left = build(ss);
        root->right = build(ss);

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));