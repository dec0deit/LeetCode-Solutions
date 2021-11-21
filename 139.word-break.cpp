/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        set<string> word_set(wordDict.begin(),wordDict.end());
        queue<int> q;
        
        int len = s.length() + 1;
        int *visit = new int[len];
        
        for(int i=0;i<len;i++){
            visit[i]=0;
        }
        
        q.push(0);
        while(!q.empty()){
            int x=q.front();
            q.pop();
            if(visit[x])
                continue;
            for(int i=x ; i<s.length() ; i++){
                if(word_set.find(s.substr(x,i-x+1)) != word_set.end()){
                    if(i+1 == s.length()){
                        return true;
                    }
                    q.push(i+1);   
                }
            }
            visit[x]=1;
        }

        return false; 
    }
};
// @lc code=end

