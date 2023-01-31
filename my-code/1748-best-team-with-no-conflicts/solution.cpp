class Solution {
public:

   int solve(vector<pair<int,int>> &p,int idx,int prev,int n,vector<vector<int>> &dp){
 
     if(idx>=n){
         return 0;
     }

     if(dp[idx][prev+1]!=-1){
         return dp[idx][prev+1];
     }
    
     int taken=0;
     int nottaken = 0+solve(p,idx+1,prev,n,dp);
     if(prev == -1 || p[idx].second>=p[prev].second ){  //second denote the scores:
          taken = p[idx].second+solve(p,idx+1,idx,n,dp);
     }
     return dp[idx][prev+1]=max(taken,nottaken);

   }
  
    //logic this->if(ages[i]>=ages[i-1] then scores[i]>=scores[i-1]) || ages[i-1]>ages[i-1] then scores[i-1]>=scores[i-1]  //replace i with idx and i-1 with prev , we use sorting by default it fix the one sort which is ages/

    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> p;
        int n=scores.size();
        vector<vector<int>> dp(n+1,vector<int>(n+2,-1));
        for(int i=0;i<n;++i){
             p.push_back({ages[i],scores[i]});  //ages sort ho chuka hai:
        }
        sort(p.begin(),p.end());//sort by default on the basie of scores:
        return solve(p,0,-1,n,dp);
    }
};



// class Solution {
// public:
//     int bestTeamScore(vector<int>& scores, vector<int>& ages) {
//         int n=ages.size();
//         vector<pair<int,int>>pair;
//         for(int i=0;i<n;i++){
//             pair.push_back({ages[i],scores[i]});
//         }
//         sort(pair.begin(),pair.end());
//         vector<vector<int>> dp(n,vector<int>(n+1,-1));

//         return getAns(pair,0,-1,dp);
//     }
//     int getAns(vector<pair<int,int>>&pair,  int ind,int prev_ind, vector<vector<int>>& dp){
        
//         if(ind == pair.size())
//             return 0;
        
//         if(dp[ind][prev_ind+1]!=-1)
//             return dp[ind][prev_ind+1];

//         int take = 0;
    
//         if(prev_ind == -1 || pair[ind].second >=pair[prev_ind].second){
//             take = pair[ind].second + getAns(pair,ind+1,ind,dp);
//         }
//         int notTake = 0 + getAns(pair,ind+1,prev_ind,dp);    
//         return dp[ind][prev_ind+1] = max(notTake,take);
// }
// };
