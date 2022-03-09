/*
 * @lc app=leetcode id=413 lang=cpp
 *
 * [413] Arithmetic Slices
 */

// @lc code=start
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int cnt = 0;
        int res = 0;
        for (int i=1;i<nums.size()-1;i++){
            if (nums[i+1]-nums[i]==nums[i]-nums[i-1]){
                cnt++;
                res +=cnt;
            }
            else{
                cnt = 0;
            }
        }
        return res;
    }
};
// @lc code=end

