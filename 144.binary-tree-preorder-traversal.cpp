/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
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
    vector<int> res;
    void traversal(TreeNode* root){
        if(root == nullptr)
            return ;
       
        res.push_back(root->val);
        traversal(root->left);
        traversal(root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        traversal(root);

        return res;
    }
};
// @lc code=end

