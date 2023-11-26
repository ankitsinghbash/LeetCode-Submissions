class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        
        for(int i=1;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]==1){
                int prev = matrix[i-1][j];
                int val = matrix[i][j];
                matrix[i][j] = prev+val;
                }
            }
        }

        int maxx=0;
        int n = matrix.size()-1;
        for(int i=n;i>=0;i--){
             vector<int> store;
             for(int j=0;j<matrix[i].size();j++){
                 int val = matrix[i][j];
                 store.push_back(val);
             }

             sort(store.begin(),store.end(),greater<int>());
             
             for(int i=0;i<store.size();i++){
                 cout<<"store"<<store[i]<<" ";
                 int width = i+1;
                 int val = store[i];
                 int area = 0;
                 if(val!=0){
                       area = width*val;
                 }
                 maxx = max(maxx,area);
             }
             store.clear();
        }



        return maxx;
 
     
    }
};
