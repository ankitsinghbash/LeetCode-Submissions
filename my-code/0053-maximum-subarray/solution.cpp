class Solution {
public:
    int maxx = INT_MIN;
    int solve(vector<int> &nums,int n,int idx,int sum){
 
        if(idx>=n){
          return 0;
        }
  
        sum+=nums[idx]+solve(nums,n,idx+1,sum);
        maxx=max(maxx,sum);
        if(sum<0){
          sum=0;
        }
        
        return sum;
     }
 
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        solve(nums,n,0,0);
        return maxx;    
    }
};
