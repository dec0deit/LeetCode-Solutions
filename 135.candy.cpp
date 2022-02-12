/*
 * @lc app=leetcode id=135 lang=cpp
 *
 * [135] Candy
 */

// @lc code=start
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> result(ratings.size(),1);
        for(int i=1;i<ratings.size();i++){
            if(ratings[i-1]<ratings[i]){
                result[i]=result[i-1]+1;
            }

        }
        
        for(int i=ratings.size()-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                result[i]=max(result[i],result[i+1]+1);
            }
        }
        int sum = 0;
        for(auto it : result)
            sum+=it;

        return sum;
    }
};
// @lc code=end

