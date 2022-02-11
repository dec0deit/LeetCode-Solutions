/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        int str = 0;
        int end = s.length()-1;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        while(str<=end){
            
            if((s[str]<'a' || s[str]>'z') && (s[str]<'0' || s[str]>'9'))
                str++;
            else if((s[end]<'a' || s[end]>'z')&& (s[end]<'0' || s[end]>'9'))
                end--;
            else if(s[str]==s[end]){
                str++;
                end--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

