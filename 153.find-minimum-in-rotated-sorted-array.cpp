/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {


        int str = 0;
        int end = nums.size()-1;
        int index = -1;
        while(str<=end){
            int mid=(str+end)/2;
            if(mid+1<nums.size() && nums[mid]>nums[mid+1]){
                index = mid+1;
                break;
            }
            else if(mid-1>=0 && nums[mid]<nums[mid-1]){
                index = mid;
                break;
            }
            if(nums[end]<nums[mid]){
                str=mid+1;
            }
            else{
                end=mid-1;
            }
        }   
        if(index == -1)
            return nums[0];

        return nums[index];
    }
};
// @lc code=end

