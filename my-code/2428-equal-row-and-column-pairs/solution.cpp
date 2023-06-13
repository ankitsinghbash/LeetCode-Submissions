class Solution {
public:

   bool check(vector<int> first,vector<int> second){
       for(int i=0;i<first.size();i++){
           if(first[i]!=second[i]){
               return false;
           }
       }
       return true;
   }


    int equalPairs(vector<vector<int>>& grid) {
        //brute force:
        //store sum and vector simantenously:
        vector<pair<int,vector<int>>> rowstore;
        for(int i=0;i<grid.size();i++){
            vector<int> sm;
            int sum = 0;
            for(int j=0;j<grid[0].size();j++){
                 sum+=grid[i][j];
                 sm.push_back(grid[i][j]);
            }
            rowstore.push_back({sum,sm});
            sm.clear();
        }


       for(int i=0;i<rowstore.size();i++){
           cout<<rowstore[i].first<<" ,";
       }
       cout<<endl;

        
        vector<pair<int,vector<int>>> colstore;
        for(int j=0;j<grid[0].size();j++){
            int sum=0;
            vector<int> sm;
            for(int i=0;i<grid.size();i++){
                  sum+=grid[i][j];
                  sm.push_back(grid[i][j]);
            }
            colstore.push_back({sum,sm});
            sm.clear();
        }
      
        for(int i=0;i<colstore.size();i++){
           cout<<colstore[i].first<<" ,";
       }


       int cnt=0;
       for(int i=0;i<rowstore.size();i++){
           int sumi = rowstore[i].first;
           vector<int> row_vec = rowstore[i].second;
           for(int j=0;j<colstore.size();j++){
               int sumj = colstore[j].first;
               vector<int> col_vec = colstore[j].second;
               if(sumi==sumj){
                   if(check(row_vec,col_vec)){
                       cnt++;
                   }
               }
           }
       }
       return cnt;



    }
};
