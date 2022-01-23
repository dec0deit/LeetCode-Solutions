/*
 * @lc app=leetcode id=617 lang=cpp
 *
 * [617] Merge Two Binary Trees
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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {

        if(root2==nullptr){
            return root1;
        }
        if(root1==nullptr){
            return root2;
        }
        stack<TreeNode*> st;
        st.push(root1);
        st.push(root2);       
        
        while(st.size()>=2){
            TreeNode* temp2=(st.top());
            st.pop();
            TreeNode* temp1=(st.top());
            st.pop();
            temp1->val+=temp2->val;
            if(temp2->left!=nullptr && temp1->left==nullptr){
                temp1->left=temp2->left;
            }
            else if(temp2->left!=nullptr && temp1->left!=nullptr){
                st.push(temp1->left);
                st.push(temp2->left);
            }

            if(temp2->right!=nullptr && temp1->right==nullptr){
                temp1->right=temp2->right;
            }
            else if(temp2->right!=nullptr && temp1->right!=nullptr){
                st.push(temp1->right);
                st.push(temp2->right);
            }
        }

        return root1;
    }
};
// @lc code=end

