/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == nullptr){
            return {};
        }
        vector<vector<int>> v;
        queue<pair<int,TreeNode*>> q;
        q.push({1,root});
        while(!q.empty()){ 
            pair<int,TreeNode*> t = q.front();
            if(v.size()<t.first){
                vector<int> v1;
                v1.push_back(t.second->val);
                v.push_back(v1);
            }
            else{
                v[t.first-1].push_back(t.second->val);
            }
            q.pop();
            if(t.second->left != nullptr){
                q.push({t.first+1,t.second->left});
            }
            if(t.second->right != nullptr){
                q.push({t.first+1,t.second->right});
            }
        }
        reverse(v.begin(),v.end());
        return v;
    }
};
// @lc code=end

