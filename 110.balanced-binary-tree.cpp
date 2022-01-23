/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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

    bool isBalanc = true;
    int height(TreeNode* treeBalanced){
        if(treeBalanced == nullptr){
            return 0;
        }
        if(treeBalanced->left == nullptr && treeBalanced->right == nullptr){
            return 1;
        }
        int left = height(treeBalanced->left);
        int right = height(treeBalanced->right);
        int h = 1 + max(left,right);
        if(abs(left-right)>1){
            isBalanc = false;
        }
        return h;
    }
    bool isBalanced(TreeNode* root) {
        height(root);

        return isBalanc;
    }
};
// @lc code=end

