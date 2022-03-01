/*
 * @lc app=leetcode id=168 lang=cpp
 *
 * [168] Excel Sheet Column Title
 */

// @lc code=start
class Solution {
public:
    string convertToTitle(int columnNumber) {
       
        string res="";
        while(columnNumber>0){
            int rem = columnNumber%26;
            if(rem == 0){
                res+='Z';
                columnNumber--;
            }
            else{
                res+=(rem+64);
            }

            
            columnNumber /= 26;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
// @lc code=end

