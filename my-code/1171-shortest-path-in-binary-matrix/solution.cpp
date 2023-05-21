class Solution {
public:
   vector<vector<int>> direction = {{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1}};
 
   bool isSafe(int i,int j,vector<vector<int>> &grid){
       if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()){
           return false;
       }
       return true;
   }
 

   typedef pair<int,pair<int,int>> P;
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        priority_queue<P,vector<P>,greater<P>> pq;
        int n = grid.size();
        int m = grid.size();
        if(n==0 || m==0 || grid[0][0]==1 || grid[n-1][n-1]==1){
            return -1;
        }


        vector<vector<int>> result(n,vector<int>(m,INT_MAX));
        pq.push({0,{0,0}});
        result[0][0]=0;
        grid[0][0]=1;


        while(!pq.empty()){
            int size = pq.size();
            while(size--){
                int d = pq.top().first;
                pair<int,int> node = pq.top().second;
                int x = node.first;
                int y = node.second;
                pq.pop();

                for(auto &dir : direction){
                    int x_ = x+dir[0];
                    int y_ = y+dir[1];

                    int dist = 1;

                    if(isSafe(x_,y_,grid) && grid[x_][y_]==0 && d+dist<result[x_][y_]){
                        result[x_][y_] = d+dist;
                        pq.push({d+dist,{x_,y_}});
                        grid[x_][y_]=1;
                    }
                }
            }
        }

        if(result[n-1][m-1]==INT_MAX){
            return -1;
        }
        return result[n-1][m-1]+1;
    }
};
