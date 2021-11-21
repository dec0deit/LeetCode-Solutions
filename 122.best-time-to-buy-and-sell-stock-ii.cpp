/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int curr = 0;
        for(int i=0;i<prices.size();){
            curr = prices[i];
            int index=i+1;
            while(index<prices.size() && 
                    prices[index-1]<=prices[index]){
                index++;     
            }
           // cout<<index<<" ";
            profit += prices[index-1]-prices[i];
            i=index;
        }
        return profit;   
    }
};
// @lc code=end

