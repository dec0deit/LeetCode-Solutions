/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
public:
    int **dp;
    int result(vector<int> &prices,int i,int flag){
        if(i == prices.size()){
            return 0;
        }
        if(dp[i][flag]!=-1){
            return dp[i][flag];
        }
        if(flag == 2){
            return 0;
        }
        if(flag == 0){
            return dp[i][flag]=max(-prices[i]+result(prices,i+1,1-flag),result(prices,i+1,flag));
        }
        else{
            return dp[i][flag]=max(prices[i]+result(prices,i+1,2),result(prices,i+1,flag));
        }
    }*--
    int maxProfit(vector<int>& prices) {
        dp = new int*[prices.size()+1];
        for(int i=0;i<prices.size();i++){
            dp[i] = new int[3];
            for(int j=0;j<3;j++)
                dp[i][j]=-1;
        }
        int maxi = 0;
        return result(prices,0,0);
    }
};
// @lc code=end

