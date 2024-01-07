class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n  = nums.size();
        vector<unordered_map<long long int,long long int>> mp(n);
        long long int ans=0;
        mp[0][0]=0;
        for(int i=1;i<nums.size();i++){
               for(int j=i-1;j>=0;j--){
                   long long int diff = static_cast<long long>(nums[i])-nums[j];
                   if(mp[j].find(diff)!=mp[j].end()){
                         ans+=mp[j][diff];

                   }
                   mp[i][diff] += mp[j][diff]+1;
               }
        }
        return ans;
    }
};
