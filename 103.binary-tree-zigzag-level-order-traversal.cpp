/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
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
#define ll long long int
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        ll flag=0;
        if(root == nullptr){
            return {};
        }
        stack<TreeNode*> current,newStack;
        vector<vector<int>> final1; 
        vector<int> temp;
        current.push(root);
        while(!current.empty()){
            TreeNode* temp1=current.top();
            current.pop();
            if(flag){
                temp.push_back(temp1->val);
                if(temp1->right)
                    newStack.push(temp1->right);
                if(temp1->left)
                newStack.push(temp1->left);
            }
            else{
                temp.push_back(temp1->val);
                if(temp1->left)
                    newStack.push(temp1->left);
                if(temp1->right)
                newStack.push(temp1->right);
            }
            if(current.empty()){
                cout<<"working"<<endl;
                flag=1-flag;
                swap(current,newStack);
                final1.push_back(temp);
                temp.clear();
            }
        }


        return final1;
    }
};
// @lc code=end

