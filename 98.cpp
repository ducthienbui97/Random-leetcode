/**
 * Leetcode 98. Validate Binary Search Tree
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    struct Response{
        bool valid;
        int MAX,MIN;
    };    
    int max(int x,int y, int z){
        return std::max(std::max(x,y),z);
    }
    int min(int x,int y, int z){
        return std::min(std::min(x,y),z);
    }
public:
    Response validate(TreeNode* root){
        if(root == nullptr) return {true,0,0};
        if(root -> left == nullptr && root -> right == nullptr) return {true,root->val,root->val};
        Response LEFT = validate(root -> left);
        Response RIGHT = validate(root -> right);
        Response rep = {LEFT.valid & RIGHT.valid, RIGHT.MAX, LEFT.MIN };
        if(root -> left == nullptr){
            rep.MIN = root -> val;
            rep.valid &= root -> val < RIGHT.MIN;
        }
        else if(root -> right == nullptr){
            rep.MAX = root -> val;
            rep.valid &= root -> val > LEFT.MAX;
        }
        else{
            rep.valid &= root -> val > LEFT.MAX & root -> val < RIGHT.MIN;
        }
        return rep;
    }
    bool isValidBST(TreeNode* root) {

        return validate(root).valid;
    }
};
