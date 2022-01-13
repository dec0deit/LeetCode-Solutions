/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */

// @lc code=start
class Solution {
public:
    // int solve(vector<vector<int>> &triangle,int i,int j,int n){
    //     if(i==n){
    //         return 0;
    //     }
    //     if(dp[i][j] != -1){
    //         return dp[i];
    //     }
    //     int ans = 1e9;
    //     ans =  min(ans,triangle[i-1]+solve(triangle,i+1,n));


    //     return dp[i] = ans;
    // } vector<int> dp;
   
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> miniOneMatrix(triangle.back());
        for (int layer = n-2; layer >= 0; layer--) // For each layer
        {
            for (int i = 0; i <= layer; i++) // Check its every 'node'
            {
            // Find the lesser of its two children, and sum the current value in the triangle with it.
                miniOneMatrix[i] = min(miniOneMatrix[i], miniOneMatrix[i+1]) + triangle[layer][i]; 
            }
        }
    return miniOneMatrix[0];
    }
};
// @lc code=end


