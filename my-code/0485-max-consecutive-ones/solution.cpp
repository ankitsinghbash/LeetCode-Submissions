class Solution {
    public:
    
    //recusion solution;
    int maxx=INT_MIN;
    int ans=0;
    void solve(vector<int> &nums,int idx){

     if(idx==nums.size()){
         return;
     }

     solve(nums,idx+1);
     if(nums[idx]==1){
         ans++;
     }
     else{
         ans=0;
     }
     maxx=max(maxx,ans);
    }

    int findMaxConsecutiveOnes(vector<int>& nums) {
          
        solve(nums,0);
         return maxx;
        
        
    }
};
