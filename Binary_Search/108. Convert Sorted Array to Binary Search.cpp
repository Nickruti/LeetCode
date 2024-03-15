// Link to the Leetcode Problem - https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
// Time Complexity = O(N)
// Auxiliary Space = O(H) ~= O(log(N))

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
    TreeNode* sortedArrToBST(vector<int>& arr, int first, int last){
        if(first > last){
            return NULL;
        }

        int mid = (first + last)/2;
        TreeNode *root = new TreeNode();
        root->val = arr[mid];
        root->left = sortedArrToBST(arr, first, mid - 1);
        root->right = sortedArrToBST(arr, mid + 1, last);

        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        TreeNode* root = sortedArrToBST(nums, 0, n - 1);
        return root;
    }
};
