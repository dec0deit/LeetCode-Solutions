/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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
    map<int,vector<int>> mp;

    void finalResult(TreeNode* root,int height){
        if(root==nullptr){
            return ;
        }

        mp[height].push_back(root->val);
        finalResult(root->left,height+1);
        finalResult(root->right,height+1);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        finalResult(root,0);
        for(auto it : mp){
            vector<int> temp;
            for(auto it1 : it.second){
                temp.push_back(it1);
            }
            v.push_back(temp);
        }

        return v;
    }
};
// @lc code=end

