// Link to the Problem - https://leetcode.com/problems/minimum-depth-of-binary-tree/description/
// Topics = Tree, Depth-First Search, Breadth-First Search, Binary Tree
// Beats 89.52% of users with C++
// My Solution -------------------------------------------------------------------
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
    int findMinDepth(TreeNode* p, int height){
        if(p == NULL){
            return 0;
        }
        if(p->left == NULL && p->right == NULL){
            return height + 1;
        } else {
            height++;
            int leftHeight = 0;
            if(p->left != NULL)
                leftHeight = findMinDepth(p->left, height);
            int rightHeight = 0;
            if(p->right != NULL)
                rightHeight = findMinDepth(p->right, height);
            return leftHeight > 0 && rightHeight > 0 ? min(leftHeight, rightHeight) : max(leftHeight, rightHeight);
        }
    }
    int minDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        return findMinDepth(root, 0);
    }
};
