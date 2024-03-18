// Link to the problem - https://leetcode.com/problems/same-tree/description/
// 0 ms Beats 100.00% of users with C++
// Topics => Tree, Depth-First Search, Breadth-First Search, Binary Tree

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

    bool isTreeSame(TreeNode* p, TreeNode* q){
        if(p == NULL && q == NULL){
            return true;
        }
        if(p != NULL && q != NULL && p->val == q->val){
            bool leftNode = isTreeSame(p->left, q->left);
            bool rightNode = isTreeSame(p->right, q->right);
            if (leftNode && rightNode){
                return true;
            } else {
                return false;
            }
        }
        else{
            return false;
        }
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL){
            return true;
        } 
        return isTreeSame(p, q);
    }
};
