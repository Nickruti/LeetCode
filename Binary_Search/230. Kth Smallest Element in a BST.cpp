// URL - https://leetcode.com/problems/kth-smallest-element-in-a-bst/

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
    int ansNode = 0;
    int ans = -1;
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return 0;
        
        kthSmallest(root->left, k);
        ansNode++;
        if(ansNode == k)
        {
            ans = root->val;
        }
        kthSmallest(root->right, k);
        
        return ans;
    }
};