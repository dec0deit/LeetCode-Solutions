/*
 * @lc app=leetcode id=126 lang=cpp
 *
 * [126] Word Ladder II
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        string temp="";
        map<string,vector<string>> mp;
        for(auto it : wordList){
            for(int i=0;i<it.size();i++){
                temp=it.substr(0,i) +"*"+it.substr(i+1);
                mp[temp].push_back(it);
            }
        }

        queue<vector<string>> q;
        q.push({beginWord});
        map<string,int> visit;
        int minLevel = 1e9;
        vector<vector<string>> ans;
        visit[beginWord]++;
        while(!q.empty()){
            vector<string> curr = q.front();
            q.pop();
            if(minLevel<=curr.size()){
                continue;
            }
            string final = curr.back();
            visit[final]=1;
            for(int i=0;i<final.size();i++){
                string rem = final.substr(0,i)+"*"+final.substr(i+1);
                bool flag = 0;
                for(auto it : mp[rem]){
                    if(it == endWord){
                        minLevel = min((int)minLevel,(int)curr.size()+1);
                        curr.push_back(endWord);
                        ans.push_back(curr);
                    }
                    else if(visit[it]==0){
                        vector<string> tep = curr;
                        tep.push_back(it);
                        q.push(tep);
                    }
                }
                if(flag)
                    break;
            }
        }
        return ans;
    }
};
// @lc code=end

