/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    int ind=0;
    
    int findInd(int val,vector<int> ino,int str,int end){
        for(int i=str;i<=end;i++){
            if(ino[i] == val){
                return i;
            }
        }
        return -1;
    }

    TreeNode* result(vector<int> &pre,vector<int> &ino,int str,int end){
        if(str > end)
            return nullptr;
        if(ind==pre.size())
            return nullptr;
        int index=findInd(pre[ind++],ino,str,end);
        TreeNode* temp = new TreeNode(ino[index],result(pre,ino,str,index-1),result(pre,ino,index+1,end));
        return temp;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {        
        return result(preorder, inorder,0,inorder.size());
    }
};
// @lc code=end

