/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 */

// @lc code=start
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(),wordList.end());
        queue<string> todo;
        int count = 1;
        todo.push(beginWord);
        while(!todo.empty()){
            int n = todo.size();
            for(int k=0;k<n;k++){ 
                string temp = todo.front();
                s.erase(temp);
                if(temp == endWord){
                    return count;
                }  
                todo.pop();
                for(auto &it : temp){
                    char temp1 = it;
                    for(char i='a';i<='z';i++){
                        it = i; 
                        if(s.find(temp)!=s.end()){
                            todo.push(temp);
                        }
                    }
                    it = temp1;
                }
            }
            count++;
        }

        return 0;
    }
};
// @lc code=end

