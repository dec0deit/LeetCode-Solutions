/*
* @lc app=leetcode id=134 lang=cpp
*
* [134] Gas Station
*/
// @lc code=start
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
       int index = 0;
       int total = 0;
       int sum = 0;
       for(int i=0;i<gas.size();i++){
           sum+=gas[i]-cost[i];
           if(sum<0){
               sum = 0;
               index = i+1;
           }
           total+=gas[i]-cost[i];
       }
       if(total<0)
        return -1;

       return index;
    }
};
// @lc code=end

