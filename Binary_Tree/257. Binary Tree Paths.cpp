// Link to the Problem - https://leetcode.com/problems/binary-tree-paths/description/
// topics - String, Backtracking, Tree, Depth-First Search, Binary Tree
// Runtime 4 ms Beats 50.61% of users with C++

// my Solution --------------------------------
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
    vector<string> pathsToLeaf;
    string pathsUptoLeafNodes(TreeNode *p, string path){
        if(p == NULL){
            return "";
        }
        if(path.empty()){
            path = to_string(p->val);
        } else {
            path += "->" + to_string(p->val);
        }
        if(p->left == NULL && p->right == NULL){
            pathsToLeaf.push_back(path);
            return path;
        }
        pathsUptoLeafNodes(p->left, path);
        pathsUptoLeafNodes(p->right, path);
        return path;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string path = "";
        if(root->left == NULL && root->right == NULL){
            path = to_string(root->val);
            pathsToLeaf.push_back(path);
            return pathsToLeaf;
        }

        pathsUptoLeafNodes(root, path);   
        return pathsToLeaf;     
    }
};
