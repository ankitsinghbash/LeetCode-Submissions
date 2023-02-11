class Solution {
public:

    int maxDistance(vector<vector<int>>& grid) {

        queue<pair<int,int>> qu;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                   qu.push({i,j});
                }
            }
        }
        
      if(qu.size()==0 || qu.size()==grid.size()*grid[0].size()){
          return -1;
      }
   
    
       int level=-1;
       int dir[4][4]={{0,1},{1,0},{0,-1},{-1,0}};
       while(!qu.empty()){
           level++;
          int size = qu.size();
          while(size--){
            pair<int,int> P = qu.front();
            int xcord = P.first;
            int ycord = P.second;
            qu.pop();
            for(int i=0;i<4;i++){
               int rcol = xcord+dir[i][0];
               int ccol = ycord+dir[i][1];
               if(rcol<0 || ccol<0 ||rcol>=grid.size() || ccol>=grid[0].size() || grid[rcol][ccol]==1){
                   continue;
               }
               grid[rcol][ccol]=1;
               qu.push({rcol,ccol});
            }
          }
       
       }
       return level;
    }
};

// class Solution {
// public:
//     int maxDistance(vector<vector<int>>& grid) {
//         queue<pair<int,int>>q;
//         for(int i=0;i<grid.size();i++){
//             for(int j=0;j<grid[0].size();j++){
//                 if(grid[i][j]==1){
//                     q.push({i,j});
//                 }
//             }
//         }

//         if(q.size()==0 or q.size()==(grid.size()*grid[0].size())){
//             return -1;
//         }
//         int level=-1;
//         int dir[4][4]={{0,1},{1,0},{0,-1},{-1,0}};
//         while(!q.empty()){
//             level++;
//             int time=q.size();
//             while(time--){
//                 auto x=q.front();
//                 q.pop();
//                 for(int i=0;i<4;i++){
//                     int nrow=x.first+dir[i][0];
//                     int ncol=x.second+dir[i][1];
//                     if(nrow<0 or ncol<0 or nrow>=grid.size() or ncol>=grid[0].size() or grid[nrow][ncol]==1){
//                         continue;
//                     }
//                     q.push({nrow,ncol});
//                     grid[nrow][ncol]=1;
//                 }
//             }
//         }
//         return level;
//     }
// };
