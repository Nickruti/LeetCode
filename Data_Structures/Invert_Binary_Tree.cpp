/*
url - https://leetcode.com/problems/invert-binary-tree/

*/
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        
        TreeNode* temp = root->right;
        root->right = root->left;
        root->left = temp;
        
        invertTree(root->right);
        invertTree(root->left);
        return root;
        
    }
};
