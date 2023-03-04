class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
       int cnt=0;
       unordered_map<int,int> mp;
       int sum=0;
       for(int i=0;i<nums.size();++i){
             sum+=nums[i];
              int r=sum%k;
              if(r==0){
                  cnt++;
              }
              if(r<0){
                  r+=k;
              }
              cnt+=mp[r];
             
              ++mp[r];
       }
       return cnt;
    }
};
