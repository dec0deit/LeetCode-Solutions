/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
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
       
        traversal(root->left);
        traversal(root->right);
        res.push_back(root->val);
        
    }
    vector<int> postorderTraversal(TreeNode* root) {
        traversal(root);
        return res;
    }
};
// @lc code=end

