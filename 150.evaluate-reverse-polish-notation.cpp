/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<int> s;
        for(auto it : tokens){
            
          
            
            if(it=="+"){
                  int x = s.top();
            s.pop();
            int y = s.top();
            s.pop();
                s.push(x+y);
            }
            else if(it=="*"){
                  int x = s.top();
            s.pop();
            int y = s.top();
            s.pop();
                s.push(x*y);
            }
            else if(it == "/"){
                  int x = s.top();
            s.pop();
            int y = s.top();
            s.pop();
                s.push(y/x);
            }
            else if(it == "^"){
                  int x = s.top();
            s.pop();
            int y = s.top();
            s.pop();
                s.push(y^x);
            }
            else if(it=="-"){
                  int x = s.top();
            s.pop();
            int y = s.top();
            s.pop();
                s.push(y-x);
            }
            else{
                s.push(stoi(it));
            } 
        }

        return s.top();
    }
};
// @lc code=end

