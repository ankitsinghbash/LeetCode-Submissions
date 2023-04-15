class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> ans;
        for(int j=0;j<m;j++){
            int maxx=0;
            for(int i=0;i<n;i++){
                int val = grid[i][j];
                string str = to_string(val);
                int size_max = str.size();
                maxx=max(maxx,size_max);
            }
            ans.push_back(maxx);
        }
        return ans;
    }
};
