class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> store;
        for(int j=0;j<matrix[0].size();j++){
             vector<int> sm;
             for(int i=matrix.size()-1;i>=0;i--){
                  sm.push_back(matrix[i][j]);
                  cout<<matrix[i][j]<<" ";
             }
            store.push_back(sm);
        }
        
        
        for(int i=0;i<store.size();i++){
            for(int j=0;j<store[0].size();j++){
                matrix[i][j]=store[i][j];
            }
            
        }
    }
};
