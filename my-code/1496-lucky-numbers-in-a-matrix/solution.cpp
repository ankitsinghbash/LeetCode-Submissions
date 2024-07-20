class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        //first we have to store the min number of our row:
        vector<int> box_min;
        for(int i=0;i<matrix.size();i++){
                 int mini =   INT_MAX;
                 int idx=-1;
                 for(int j=0;j<matrix[0].size();j++){
                      if(mini>matrix[i][j]){
                             mini = matrix[i][j];
                             idx = j;
                      }
                 }
               box_min.push_back(idx);
        }


        int k=0;
        while(k<box_min.size()){
            int x  = k;
            int y = box_min[k];

            int value = matrix[x][y];
            int maxx = INT_MIN;
            //now check if value is the maximum value in the row x and col y then it's out ans just break the loop:
            for(int i=0;i<matrix.size();i++){
                 int grid  = matrix[i][y];
                 maxx = max(maxx,grid);
            }
 
           vector<int> ans;
           if(value==maxx){
                ans.push_back(value);
                return ans;
            
           }
           k++;

        }
        return {};

          


    } 
};
