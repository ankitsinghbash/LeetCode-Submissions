class Solution {
public:
    bool dfs(int i,int j,int idx,vector<vector<char>> &board,string word,vector<vector<bool>> &visited){
            if(idx==word.size()) return true;
            
             if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || visited[i][j]==true || word[idx]!=board[i][j]) return false;


            visited[i][j]=true;
            bool f1 = dfs(i+1,j,idx+1,board,word,visited);
            bool f2 = dfs(i-1,j,idx+1,board,word,visited);
            bool f3 = dfs(i,j+1,idx+1,board,word,visited);
            bool f4 = dfs(i,j-1,idx+1,board,word,visited);
            visited[i][j]=false;
            return f1 || f2 || f3 || f4;
    }

    bool exist(vector<vector<char>>& board, string word) {
       
        int idx=0;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[idx]){
                    vector<vector<bool>> visited(board.size(),vector<bool>(board[0].size()));
                    if(dfs(i,j,idx,board,word,visited)==true) return true;
                }
            }
        }
        return false;
    }
};
