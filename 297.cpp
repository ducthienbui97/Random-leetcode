/**
 * Leetcode 297. Serialize and Deserialize Binary Tree
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

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr)
            return "";
        else{
            return  to_string(root->val) + "," + serialize(root -> left) + "," + serialize(root -> right);
        }
    }
    TreeNode* dfs(istringstream& parts){
        string s;
        getline(parts,s,',');
        if(s.empty())
            return nullptr;
        TreeNode* root = new TreeNode(stoi(s));
        root->left = dfs(parts);
        root->right = dfs(parts);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream parts(data);
        return dfs(parts);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
