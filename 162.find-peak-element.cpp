/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */

// @lc code=start
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int str=0;
        int n = nums.size();
        int end=nums.size()-1;
        while(str<=end){
            int mid=(str+end)/2;
            if((mid == 0 || nums[mid-1]<=nums[mid]) && (mid == n-1 || nums[mid+1]<=nums[mid])){
                return mid;
            }
            else if(mid>0 && nums[mid-1] > nums[mid] ){
                end=mid-1;
            }
            else{
                str=mid+1;
            }
        }

        return -1;
    }
};
// @lc code=end

