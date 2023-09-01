class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n,0);
        int prefix_sum=0;
        for(int i=0;i<n;i++){
              prefix[i]=prefix_sum;
              prefix_sum+=nums[i];
        }
       vector<int> suffix(n,0);
       int suffix_sum=0;
       for(int i=n-1;i>=0;i--){
           suffix[i]=suffix_sum;
           suffix_sum+=nums[i];
       }    
      
       vector<int> ans(n,0);
       for(int i=0;i<prefix.size();i++){
           int diff = abs(prefix[i]-suffix[i]);
           ans[i]=diff;
       }
       return ans;
    }
};
