/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
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
    void flatten1(TreeNode* root){
        if(root == nullptr || (root->left == nullptr && root->right == nullptr)){
            return ;
        }
        cout<<"working"<<" ";
        if(root->left != nullptr){
            flatten1(root->left);
            TreeNode* temp = root->right;
            root->right = root->left;
            root->left = nullptr;
            TreeNode* t1 = root->right;
            while(t1->right != nullptr){
                t1=t1->right;
            }
            t1->right = temp;
        }
        flatten1(root->right);
    }
    void preorder(TreeNode* root)
    {
        if(root == nullptr){
            return ;
        }
        preorder(root->left);
        cout<<root->val<<" ";
        preorder(root->right);
    }
    void flatten(TreeNode* root) {
        flatten1(root);
        //preorder(root);
    }
};
// @lc code=end

