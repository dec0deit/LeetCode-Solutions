/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
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
    vector<vector<int>> v;
    void solve(TreeNode* root,vector<int> &v1,int targetSum){
        if(root == nullptr){
            return ;
        }
        if(targetSum == root->val && root->left == nullptr
                                && root->right == nullptr){

            v1.push_back(root->val);
            v.push_back(v1);
            v1.pop_back();
            return ;
        }
        else{
            
            v1.push_back(root->val);
            
            if(root->left != nullptr)
                solve(root->left,v1,targetSum-root->val);
            
            if(root->right != nullptr)
                solve(root->right,v1,targetSum-root->val);

            v1.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> v1;
        solve(root,v1,targetSum);
        return v;
    }
};
// @lc code=end

