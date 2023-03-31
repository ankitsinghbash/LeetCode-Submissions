#define mod 1000000007
class Solution {
public:
 int res=0;
 int solve(vector<vector<int>>&apple_cnt,vector<vector<vector<int>>> &dp,int rn,int cn,int cuts){

     //base case
     if(cuts==0){
         if(apple_cnt[rn][cn]>0) return 1;
         else 
          return 0;
     }

     if(dp[rn][cn][cuts] != -1){
         return dp[rn][cn][cuts];
     }

     long long int rows=0,col=0;

     for(int i=rn+1;i<apple_cnt.size();i++){
         if(apple_cnt[i][cn]>=cuts && apple_cnt[rn][cn]-apple_cnt[i][cn]>0){
             rows+=(solve(apple_cnt,dp,i,cn,cuts-1))%mod;
         }
     }
     for(int j=cn+1;j<apple_cnt[0].size();j++){
         if(apple_cnt[rn][j]>=cuts && apple_cnt[rn][cn]-apple_cnt[rn][j]>0){
             col+=(solve(apple_cnt,dp,rn,j,cuts-1))%mod;
         }
     }
     
    dp[rn][cn][cuts]=(rows+col)%mod;

    return dp[rn][cn][cuts];



    }

    int ways(vector<string>& pizza, int k) {
      
      int n=pizza.size();
      int m=pizza[0].size();
vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+1,vector<int>(k+1,-1)));

vector<vector<int>> apple_cnt(n+1,vector<int>(m+1,0));

for(int i=n-1;i>=0;i--){
    for(int j=m-1;j>=0;j--){

        apple_cnt[i][j]= apple_cnt[i+1][j]+apple_cnt[i][j+1]-apple_cnt[i+1][j+1]+int(pizza[i][j]=='A');
    }
}
    res= solve(apple_cnt,dp,0,0,k-1);
       return res; 
    }
};
