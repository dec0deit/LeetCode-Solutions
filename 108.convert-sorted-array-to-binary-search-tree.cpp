/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
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
class Solution
{
public:
    TreeNode *makeSortedBST(vector<int> &nums, int str, int end)
    {

        if(str> end){
            return nullptr;
        }
        if (str == end)
        {
            TreeNode *temp = nullptr;
            temp = new TreeNode(nums[str]);
            return temp;
        }
        
        int mid = (str + end)/2;
        TreeNode* myNode = new TreeNode(nums[mid]);
        myNode->left = makeSortedBST(nums,str,mid-1);
        myNode->right = makeSortedBST(nums,mid+1,end);

        return myNode;
    }

    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return makeSortedBST(nums,0,nums.size()-1);
    }
};
// @lc code=end
