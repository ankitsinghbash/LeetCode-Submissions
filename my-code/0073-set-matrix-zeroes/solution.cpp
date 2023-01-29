class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //cost the ith and jth row and col is zero;
        vector<pair<int,int>> p;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    p.push_back({i,j});
                }
            }
        }
         
 
      for(auto &x : p){
  
          //for x.first mean for row;
          int j=0;
          while(j<matrix[0].size()){
              matrix[x.first][j]=0;
              j++;
          }

          //for x.second means for col;
          int i=0;
          while(i<matrix.size()){
              matrix[i][x.second]=0;
              i++;
          }

      } 

   

    }
};
