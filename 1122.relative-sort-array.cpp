/*
 * @lc app=leetcode id=1122 lang=cpp
 *
 * [1122] Relative Sort Array
 */

// @lc code=start
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        
        map<int,int> mp;
        for(auto it : arr1){
            mp[it]++;
        }
        arr1.clear();
        for(auto it : arr2){
            if(mp[it]>0){
                for(int i=0;i<mp[it];i++){
                    arr1.push_back(it);
                }
                mp[it]=0;
            }
            
        }
        for(auto it : mp){
            if(it.second>0){
                for(int i=0;i<it.second;i++){
                    arr1.push_back(it.first);
                }
            }
        }
        
        return arr1;
    }
};
// @lc code=end

