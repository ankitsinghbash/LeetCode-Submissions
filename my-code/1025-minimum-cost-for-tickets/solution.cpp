class Solution {
public:
   //index increment kar do day ke hisaab se:
  //general approach for these type of question:
   int solve(int idx,vector<int> &days,vector<int> &costs,int n,vector<int> &dp){
       if(idx>=n){
           return 0;
       }

       if(dp[idx]!=-1){
           return dp[idx];
       }

         int maxx_day_1 = days[idx]+1;   //when day=1 hoge jaise iss question me while loop nahi chalega:
         int j = idx;
         while(j<days.size() && days[j]<maxx_day_1){
              j++;
            }  

        int cost_1_day = costs[0]+solve(j,days,costs,n,dp);   //only one day pass tha to idx --goto--> next index+1:
     
        int maxx_day_7 = days[idx]+7;
        j=idx;
        while(j<n && days[j]<maxx_day_7){
            j++;
        }
     
        int cost_7_day = costs[1]+solve(j,days,costs,n,dp);

        int maxx_day_30  = days[idx]+30;
        j=idx;
        while(j<n && days[j]<maxx_day_30){
            j++;
        }

        int cost_30_day = costs[2]+solve(j,days,costs,n,dp);

        return dp[idx]=min({cost_1_day,cost_7_day,cost_30_day});
   }


    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(365,-1);
        return solve(0,days,costs,n,dp);
    }
};
