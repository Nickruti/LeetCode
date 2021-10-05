/*
url - https://leetcode.com/problems/path-sum/
*/

class Solution {
public:
    bool hasPath(TreeNode* root, int target, int cnt)
    {
        cnt += root->val;
        if(!root->left && !root->right)
        {
            if(cnt == target) return true;
            return false;
        }
        
        if(root->left && root->right) 
            return hasPath(root->left, target, cnt) || hasPath(root->right, target, cnt);
        else if (root->left) return hasPath(root->left, target, cnt);
        else return hasPath(root->right, target, cnt);
        
        
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        
        return hasPath(root, targetSum, 0);
        
    }
};
