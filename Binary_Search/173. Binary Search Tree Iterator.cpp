// URL - https://leetcode.com/problems/binary-search-tree-iterator/

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
class BSTIterator {
public:
     vector<int> ans;
    int pos;
    void inorder(TreeNode *root)
    {
        if(root==NULL) return;
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
    }
    
    
    
    BSTIterator(TreeNode* root) {
    pos=0;
        inorder(root);
    }
    
    int next() {
        return ans[pos++];
    }
    
    bool hasNext() {
        return ans.size()!=pos;
    }
//     stack<TreeNode*> s;
//     BSTIterator(TreeNode* root) {
//         partialInorder(root);
//     }
    
//     void partialInorder(TreeNode* root){
//         while(root != NULL){
//             s.push(root);
//             root = root->left;
//         }
//     }
    
//     int next() {
//         TreeNode* top = s.top();
//         s.pop();
//         partialInorder(top->right);
//         return top->val;
//     }
    
//     bool hasNext() {
//         return !s.empty();
//     }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */