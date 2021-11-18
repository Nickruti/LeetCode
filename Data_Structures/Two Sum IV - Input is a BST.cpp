/*
url - https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
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
    unordered_map<int, int> m;
    bool temp;
    void inorder(TreeNode *root, int k)
    {
        if(!root) return;
        inorder(root->left, k);
        if(m[k-root->val]) temp = true;
        else m[root->val] = 1;
        inorder(root->right, k);
    }
    
    bool findTarget(TreeNode* root, int k) {
        temp = false;
        inorder(root, k);  
        return temp;
    }
};
