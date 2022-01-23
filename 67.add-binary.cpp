/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        
        if(a.length()>b.length()){
            swap(a,b);
        }

        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());       
        int carry = 0;
        int i = 0;
        for(i=0;i<a.size();i++){
            int x = (a[i])-'0';
            int y = (b[i])-'0';

            if(carry + x + y == 3){
                b[i] = '1';
                carry = 1;
            }
            else if(carry + x + y == 2){
                b[i] = '0';
                carry = 1;
            }
            else if(carry + x + y == 1){
                carry = 0;
                b[i] = '1';
            }
            else if(carry + x + y == 0){
                b[i] = '0';
                carry = 0;
            }
        }
        
        for(int j=i;j<b.size();j++){
            int x = 0;
            int y = (b[j])-'0';

            if(carry + x + y == 3){
                b[j] = '1';
                carry = 1;
            }
            else if(carry + x + y == 2){
                b[j] = '0';
                carry = 1;
            }
            else if(carry + x + y == 1){
                carry = 0;
                b[j] = '1';
            }
            else if(carry + x + y == 0){
                b[j] = '0';
                carry = 0;
            }
        }

        if(carry == 1){
            b.push_back('1');
        }

        reverse(b.begin(),b.end());
        return b;
    }
};
// @lc code=end

