class Solution {
public:

   int solve(int n){
       int k=0;
       while(n!=0){
           int rem = n%10;
           k+=rem;
           n=n/10;
       }
       return k;
   }
    
 
    int maximumSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int maxx=-1;
        unordered_map<int,int> mp;       
 
         
        for(int i=0;i<nums.size();++i){
            int val = nums[i];
            int sum_val = solve(val);
            auto it=mp.find(sum_val);
            if(it!=mp.end()){
                //present:
                maxx=max(it->second+val,maxx);
                mp.erase(it);
            }
            mp[sum_val]=val;
        }
        return maxx;
    }
};
