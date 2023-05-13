class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        
        vector<vector<int>> matrix(nums.size(),vector<int>(nums[0].size()));
        for(vector<int> x : nums){
            sort(x.begin(),x.end(),greater<int>());
            matrix.push_back(x);
        }
        
        
        
        
        int sum = 0;
        for(int j=0;j<matrix[0].size();j++){
            int maxx = 0; // max in first row:
            for(int i=0;i<matrix.size();i++){
                maxx = max(maxx,matrix[i][j]);
            }
            sum+=maxx;
        }
        return sum;
    }
};
