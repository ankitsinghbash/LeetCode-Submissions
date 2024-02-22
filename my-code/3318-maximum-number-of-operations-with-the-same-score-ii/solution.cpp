class Solution {
public:
   
    int solve(int i,int j,vector<int> &nums,int data,vector<vector<int>> &dp){
            if(i>=j){
                return 0;
            }
         
          
            
           if(dp[i][j]!=-1){
               return dp[i][j];
           }

           int a=0;
           int b=0;
           int c=0;
           if(i+1<nums.size() && nums[i]+nums[i+1]==data){
              a = 1+solve(i+2,j,nums,data,dp);
           }
           if(i<nums.size() && j>=0 && nums[i]+nums[j]==data){
              b = 1+solve(i+1,j-1,nums,data,dp);
           }
           if(j-1>=0 && nums[j]+nums[j-1]==data){  
             c =1+solve(i,j-2,nums,data,dp);
           }
       
          return dp[i][j] = max({a,b,c});    
    }
    
    int maxOperations(vector<int>& nums) {
           int n = nums.size();
           vector<vector<int>> dp1(n+1,vector<int>(n+1,-1));
            
           int data1 = nums[0]+nums[n-1];
           int data2 = nums[0]+nums[1];
           int data3  = nums[n-1]+nums[n-2];
          
        
           int first =  1+solve(1,n-2,nums,data1,dp1);
           int second = 1+solve(2,n-1,nums,data2,dp1);
           int third = 1+solve(0,n-3,nums,data3,dp1);
               
           return max({first,second,third});
    }
};
