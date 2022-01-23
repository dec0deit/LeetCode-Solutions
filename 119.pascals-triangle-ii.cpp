/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 */

// @lc code=start
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> result;
        vector<int> v;
        v.push_back(1);
        result.push_back(v);
        for(int i=1;i<=rowIndex;i++){
            v.clear();
            v.push_back(1);
            for(int j=1;j<i;j++){
                v.push_back(result[i-1][j-1]+result[i-1][j]);
            }
            v.push_back(1);
            result.push_back(v);
        }
        return result[rowIndex];
    }
};
// @lc code=end

