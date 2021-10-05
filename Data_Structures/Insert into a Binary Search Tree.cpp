/*
url - https://leetcode.com/problems/insert-into-a-binary-search-tree/
*/

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
    TreeNode *insert(TreeNode *root, TreeNode *node)
    {
        if(root->val < node->val)
        {
            if(root->right) 
            {
                insert(root->right, node);
            }
            else root->right = node;
            
        }
        else
        {
            if(root->left)
            {
                insert(root->left, node);
            }
            else root->left = node;   
        }
        return root;
    }
        
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *node = new TreeNode(val);
        
        if(!root) return node;
        
        return insert(root, node);
        
    }
};
