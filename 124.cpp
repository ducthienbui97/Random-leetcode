/**
 * Leetcode 124. Binary Tree Maximum Path Sum
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
    pair<int,int> maxPath(TreeNode* root){
        if(root == nullptr)
            return {-1<<30,0};
        auto left = maxPath(root -> left);
        auto right = maxPath(root -> right);
        return {max(max(left.first,right.first), max(left.second,0) + max(right.second,0) + root -> val),
                max(max(left.second,right.second),0) + root -> val};
    }
    int maxPathSum(TreeNode* root) {
        return maxPath(root).first;
    }
};
