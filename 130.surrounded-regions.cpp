/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 */

// @lc code=start
class Solution {
public:

    int dx[4]={-1,0,1,0};
    int dy[4]={0,-1,0,1};
    bool check(int a,int b,vector<vector<char>> &matrix){
        if(a>=matrix.size() || a<0 || b>=matrix[0].size() || b<0)
            return false;
        return true;
    }
    void dfs(int x,int y, vector<vector<int>> &visit,vector<vector<char>> &board){
        board[x][y]='M';
        visit[x][y]=1;
        for(int i=0;i<4;i++){
            int a = dx[i]+x;
            int b = dy[i]+y;
            if(check(a,b,board) && !visit[a][b] && board[a][b]=='O')
            dfs(a,b,visit,board);
        }
    }

    void solve(vector<vector<char>>& board) {
        vector<pair<int,int>> v;
        for(int i=0;i<board[0].size();i++){
            if(board[0][i]=='O'){
                v.push_back({0,i});
            }
            if(board[board.size()-1][i]=='O'){
                v.push_back({board.size()-1,i});
            }
        }
        
        for(int i=0;i<board.size();i++){
            if(board[i][0]=='O'){
                v.push_back({i,0});
            }
            if(board[i][board[0].size()-1]=='O'){
                v.push_back({i,board[0].size()-1});
            }
        }
        vector<vector<int>> visit(board.size(),vector<int>(board[0].size(),0));
        for(auto it : v){
            if(visit[it.first][it.second]==1)
                continue;
            dfs(it.first,it.second,visit,board);
        }

        for(auto &it : board){
            for(auto &it1 : it){
                if(it1 == 'M')
                    it1 = 'O';
                else if(it1=='O'){
                    it1='X';
                }
            }
        }
    }
};
// @lc code=end

