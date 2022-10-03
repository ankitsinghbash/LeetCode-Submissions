class Solution {
public:

   bool dfs(int i,int j,vector<vector<char>> &board,string word,int counter)
   {
    
     //base:
     if(counter==word.size())
     {
         return true;
     }
    
     if(i<0||i>=board.size()||j<0||j>=board[0].size()||board[i][j]!=word.at(counter))
     return false;
      
     char temp=board[i][j];
     board[i][j]='@'; //visiting element:
      bool status = dfs(i+1,j,board,word,counter+1)||dfs(i,j+1,board,word,counter+1)||dfs(i-1,j,board,word,counter+1)||dfs(i,j-1,board,word,counter+1);
      
    board[i][j]=temp;
    return status;
   }


    bool exist(vector<vector<char>>& board, string word) {
      for(int i=0;i<board.size();i++)
      {
          for(int j=0;j<board[0].size();j++)
          {
              int counter=0;
              if(board[i][j]==word.at(0)&&dfs(i,j,board,word,counter))
              {
                  return true;
              }
          }
      }
      return false;
    }
};
