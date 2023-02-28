class Solution {
public:
  
    int solve(int n,int val,int sum){

    if(n==sum){
        return 1;
    }
    if(sum>n || val==n){
        return 0;
    }
 
     
     int  pick = val*solve(n,val,sum+val);
    int  notpick = 1*solve(n,val+1,sum);

     return max(pick,notpick);


    }
   

    int integerBreak(int n) {
        return solve(n,1,0);
    }
};

//class Solution {
// public:
//     vector<int> dp;
//     int solve(int n, int i, int sum){
//         if(sum == n) return 1;
//         if(i == n || sum > n) return 0;

//         if(dp[sum] != -1) return dp[sum];

//         return dp[sum] = max(i*solve(n, i, sum+i), solve(n, i+1, sum));}

//     int integerBreak(int n) {
//         dp = vector<int> (n+1, -1);
//         return solve(n, 1, 0);}};
