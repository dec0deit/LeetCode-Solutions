/*
 * @lc app=leetcode id=89 lang=cpp
 *
 * [89] Gray Code
 */

// @lc code=start
class Solution {
public:
    vector<string> result(int n){
        
        if(n==1){
            return {"0","1"};
        }
        vector<string> current = result(n-1);
        vector<string> res;    
        for(int i=0;i<current.size();i++)
        {
            res.push_back("0"+current[i]);
        }

        for(int i=current.size()-1;i>=0;i--){
            res.push_back("1"+current[i]);
        }

        return res;
    }
    vector<int> grayCode(int n) {
        vector<string> final = result(n);
        vector<int> v;
        for(auto it : final){
            v.push_back(stoi(it,nullptr,2));
        }
        return v;
    }
};
// @lc code=end

