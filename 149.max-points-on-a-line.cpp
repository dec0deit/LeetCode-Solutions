/*
 * @lc app=leetcode id=149 lang=cpp
 *
 * [149] Max Points on a Line
 */

// @lc code=start
class Solution
{
public:
    map<pair<int, int>, int> mp;
    pair<int,int> findSlopes(vector<int> v,vector<int> v1){
        
        int duplicates = 0;
        int x1 = v[0];
        int y1 = v[1];
        int x2 = v1[0];
        int y2 = v1[1];
        int diff =  abs(x1 - x2);
        int diff1 = abs(y1 - y2);
        int sign = ((x1 - x2) < 0) ^ ((y1 - y2) < 0) ? -1 : 1;

        if (diff == 0 && diff1 == 0){
            duplicates++;
            return {0,0};
        }
        else if (x1 - x2 == 0)
        {
            mp[{INT_MAX, INT_MAX}]++;
            return {mp[{INT_MAX, INT_MAX}], 0};
        }
        else if (y1 - y2 == 0)
        {
            mp[{0, 0}]++;
            return {mp[{0,0}], 0};
        }
        else
        {
            int x = __gcd(diff,diff1);
            diff = diff/x;
            diff1 = diff1/x;
            mp[{sign * diff, sign * diff1}]++;
        }

        return {mp[{diff * sign, diff1 * sign}], 0};
    }

    int maxPoints(vector<vector<int>> &points)
    {
        int maxi = 1;
        if(points.size()<3){
            return points.size();
        }


        for (int i = 0; i < points.size(); i++){
            mp.clear();
            int temp = 1;
            for (int j = i + 1; j < points.size(); j++){
                if(points[i]==points[j])
                    temp++;
            }  

            for (int j = i + 1; j < points.size(); j++){
                pair<int,int> p = findSlopes(points[i],points[j]);
                maxi = max(maxi,p.first+temp);
            }  
        }
        return maxi;
    }
};
// @lc code=end
