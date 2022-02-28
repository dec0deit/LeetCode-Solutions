/*
 * @lc app=leetcode id=228 lang=cpp
 *
 * [228] s Ranges
 */

// @lc code=str
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        // vector<string> res;
        // int i=0;
        // int n = nums.size();
        // while(i<n){
        //     int str=0,end=0;
        //     str = nums[i];
        //     while(i+1<n && nums[i+1]==nums[i])
        //         end=nums[i];
        //     if(str==end)
        //         res.push_back(to_string(str)+"");
        //     else
        //         res.push_back(to_string(str)+"->"+to_string(end));
            
        //     i++;
        // }

        // return res;
        int str,end,size=nums.size(); 
    
        vector<string> res;
        
        str=0;
        
        while(str<size)
        {
            end=str+1;
        
            while(end<size && nums[end] == nums[end-1]+1)
                end++;
        
            string s="";
        
            if(end == str+1)
                s += to_string(nums[str]);
            else
                s += to_string(nums[str]) + "->" + to_string(nums[end-1]);
            
            res.push_back(s);
            
            str=end;
        }
        
        return res;
    }
};
// @lc code=end

