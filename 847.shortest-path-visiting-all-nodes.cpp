/*
 * @lc app=leetcode id=847 lang=cpp
 *
 * [847] Shortest Path Visiting All Nodes
 */

// @lc code=start
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& g) {
        long long n = g.size();
        long long result = 0;
        queue<vector<long long>> q;
        vector<vector<long long>> visited(n,vector<long long>(1<<n));
        for(int i=0;i<n;i++){
            q.push({i,1<<i,0});
            visited[i][1<<i] = true;
        }
        while (!q.empty())
        {
            vector<long long> temp= q.front();
            q.pop();
            if(temp[1]==(1<<n)-1){
                result = temp[2];
                return result;  
            }
            for(auto i:g[temp[0]]){
                if(visited[i][(temp[1]|1<<i)]){
                    continue;
                }
                q.push({i,(temp[1]|1<<i),temp[2]+1});
                visited[i][(temp[1]|1<<i)] = true;
            }
        }
        return result;
    }
};
// @lc code=end

