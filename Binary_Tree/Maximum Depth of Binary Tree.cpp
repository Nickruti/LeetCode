// Url - https://leetcode.com/problems/maximum-depth-of-binary-tree/

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
    int maxD = INT_MIN;
    
    void mDepth(TreeNode *root, int cnt)
    {
        if(!root)
        {
            if (cnt > maxD)
                maxD = cnt;
            return;
        }
        cnt++;
        mDepth(root->left, cnt);
        mDepth(root->right, cnt);
        
    }
    
    int maxDepth(TreeNode* root) {
        mDepth(root, 0);
        return maxD;
    }
};