/*
 * @lc app=leetcode id=137 lang=cpp
 *
 * [137] Single Number II
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one = 0;
        int two = 0;
        int not_three = 0;
        
        for(auto it : nums){
            two = two | (one&it);
            one^=it;
            not_three = ~(one&two);
            one&=not_three;
            two&=not_three;
        }

        return one;
    }
};
// @lc code=end

