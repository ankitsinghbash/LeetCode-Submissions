class Solution {
public:
    bool is_special(int x,int y,vector<vector<int>> &mat){


       int row_sum=0;
       int col_sum=0;
       for(int i=0;i<mat.size();i++){
            if(i!=x && mat[i][y]==1){
                  row_sum+=mat[i][y];
                  break;
            }
       }
       for(int j=0;j<mat[0].size();j++){
           if(j!=y && mat[x][j]==1){
           col_sum+=mat[x][j];
           break;
           }
       }

       return row_sum==0 && col_sum==0;




    }

    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(is_special(i,j,mat) && mat[i][j]==1){
                    cnt++;
                }
            }
        }
        return cnt;
        
    }
};
