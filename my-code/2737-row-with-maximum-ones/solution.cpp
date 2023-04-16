class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        vector<int> ans;
        int max_count=0;
        int row=0;
        for(int i=0;i<mat.size();i++){
            int cnt=0;
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1){
                   cnt++; 
                }
            }
            if(cnt>max_count){
                max_count=cnt;
                row=i;
            }
        }
        ans.push_back(row);
        ans.push_back(max_count);
        return ans;
    }
};
