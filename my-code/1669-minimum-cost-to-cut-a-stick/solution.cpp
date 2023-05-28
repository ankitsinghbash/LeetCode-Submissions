class Solution {
public:
    int solve(int start,int last,vector<int> &cuts,vector<vector<int>> &dp){
      if(start>last) return 0;
      if(dp[start][last]!=-1) return dp[start][last];
      
      int mini = INT_MAX;
       for(int idx=start;idx<=last;idx++){
           int currcost = cuts[last+1]-cuts[start-1];
           int leftcost = solve(start,idx-1,cuts,dp);
           int rightcost = solve(idx+1,last,cuts,dp);
           int total = currcost + leftcost + rightcost;
           mini = min(mini,total);
       }
       return dp[start][last] = mini;

    }


    int minCost(int n, vector<int>& cuts) {
        //insert for get actual cost:
        cuts.insert(cuts.begin(),0);
        cuts.insert(cuts.end(),n);
        sort(cuts.begin(),cuts.end());  //so that cut happen:
        int m = cuts.size();
        vector<vector<int>> dp(m+1,vector<int>(m+1,-1));
        return solve(1,m-2,cuts,dp);
        
    }
};
