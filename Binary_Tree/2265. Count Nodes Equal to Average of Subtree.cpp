// Problem - 2265. Count Nodes Equal to Average of Subtree
// Link to the Problem - https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/description/
// Time Complexity = O(N)
// Space Complexity = O(N) in Worst Case - skewed tree
// Uses Recursive stack
// Runtime - 3ms, Beats 88.86%

// My Solution: 
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
    int result = 0;
    pair<int, int> postOrder(TreeNode* root){
        if (!root) return {0, 0};
        
        auto [leftNodes, leftSum] = postOrder(root->left);
        auto [rightNodes, rightSum] = postOrder(root->right);

        int currSum = leftSum + rightSum + root->val;
        int currNodes = leftNodes + rightNodes + 1;

        int currAvg = currSum / currNodes;
        if(currAvg == root->val) result++;
        return {currNodes, currSum}; 

    }
    int averageOfSubtree(TreeNode* root) {
        postOrder(root);
        return result;
    }
};
