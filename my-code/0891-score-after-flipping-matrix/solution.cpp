class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
            int n = grid.size();
            int m = grid[0].size();
            int answer=0;
            answer+=n*(1*pow(2,m-1));
            for(int j=1;j<m;j++){
                int cnt0=0;
                int total=0;
                for(int i=0;i<n;i++){
                    int current= grid[i][0]^grid[i][j];            
                    if(current==0) cnt0++;
                }
                int cnt1 = n-cnt0;
                if(cnt0>cnt1){
                    answer+=cnt0*pow(2,m-j-1);
                }
                else{
                     answer+=cnt1*pow(2,m-j-1);
                }
            }
            return answer;
    }
};
