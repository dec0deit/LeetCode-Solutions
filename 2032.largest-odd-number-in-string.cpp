/*
 * @lc app=leetcode id=2159 lang=cpp
 *
 * [2032] Two Out of Three
 */

// @lc code=start
class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        
        map<int,int> mp,mp1,mp2;
        vector<int> v;
        
        int count = 0;
        
        for(int i=0;i<nums1.size();i++){
            mp[nums1[i]]=1;
        }
        
        for(int i=0;i<nums2.size();i++){
            mp1[nums2[i]]=1;
        }
        
        for(int i=0;i<nums3.size();i++){
            mp2[nums3[i]]=1;
        }

        for(auto it : mp){
            if(it.second>0)
            if(mp1[it.first]>0 || mp2[it.first]>0){
                v.push_back(it.first);
                mp1.erase(it.first);
                mp2.erase(it.first);
            }
        }
        
        for(auto it : mp1){
            if(it.second>0)
            if(mp[it.first]>0 || mp2[it.first]>0){
                v.push_back(it.first);
                mp.erase(it.first);
                mp2.erase(it.first);
            }
        }
        
        for(auto it : mp2){
            if(it.second > 0)
            if(mp1[it.first]>0 || mp[it.first]>0){
                v.push_back(it.first);
                mp1.erase(it.first);
                mp.erase(it.first);
            }
        }
        return v;
    }
};
// @lc code=end

