/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> result;
        vector<int> v;
        v.push_back(1);
        result.push_back(v);
        for(int i=1;i<numRows;i++){
            v.clear();
            v.push_back(1);
            for(int j=1;j<i;j++){
                v.push_back(result[i-1][j-1]+result[i-1][j]);
            }
            v.push_back(1);
            result.push_back(v);
        }
        return result;
    }
};
// @lc code=end

