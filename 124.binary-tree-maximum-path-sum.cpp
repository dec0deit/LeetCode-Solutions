/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
 */

// @lc code=start
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

    int maxi = -1e9;
    int maxi1 = -1e9;
    int maxPathSumUtil(TreeNode* root){ 
        if(root == nullptr){
            return 0;
        }

        int x =  maxPathSumUtil(root->left);
        int y =  maxPathSumUtil(root->right);
        int res = 0;
        
        maxi1 = max(max(x,y)+root->val,root->val);

        int maxi2 = max(maxi1,x+y+root->val);
        maxi = max(maxi2,maxi);
        return maxi1;
    }
    int maxPathSum(TreeNode* root) {
         maxPathSumUtil(root);
         return maxi;
    }
};
// @lc code=end

