class Solution {
public:
    int ans  = 0;
    int dfs(int i,int n,vector<int> &cost){
       if(i>=n){
           return 0;
       }  
         
       int left_cost = dfs(2*i+1,n,cost);
       int right_cost = dfs(2*i+2,n,cost);
       ans+=abs(left_cost-right_cost);
       return cost[i]+max(left_cost,right_cost);
      
    }
    
    int minIncrements(int n, vector<int>& cost) {
      dfs(0,n,cost);
      return ans;
    }
};
