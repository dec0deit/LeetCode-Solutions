/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int sum = 0;
        for(auto it : nums){
            sum ^= it;
        }

        return sum;
    }
};
// @lc code=end

