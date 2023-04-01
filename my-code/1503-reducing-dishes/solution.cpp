class Solution {
public:
    
    int solve(vector<int> &arr,int idx,int cnt,vector<vector<int>> &dp){
        if(idx>=arr.size()){
            return 0;   //minimum taken nahi karuga fir zero hoga answer:
        }
        
        if(dp[idx][cnt]!=-1){
            return dp[idx][cnt];
        }
        int pick = arr[idx]*cnt + solve(arr,idx+1,cnt+1,dp);
        int notpick = 0+solve(arr,idx+1,cnt,dp);
        return dp[idx][cnt]=max(pick,notpick);
    }
    
    
    int maxSatisfaction(vector<int>& satisfaction) {
        
        sort(satisfaction.begin(),satisfaction.end()); //because i have choise at each ki kisno pick karu sort karne se last me big value hogi means cnt ka multiple big value dega:
        vector<vector<int>> dp(500,vector<int>(500,-1));
        return solve(satisfaction,0,1,dp);
    }
};
