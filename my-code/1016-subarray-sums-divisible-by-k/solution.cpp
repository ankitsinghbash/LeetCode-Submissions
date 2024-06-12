class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
       
        unordered_map<int,int> mp;
        mp[0]=1;
        int current=0;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
               current+=nums[i];
               int mod = current%k;
               if(mod<0){
                 mod+=k;
               }
               if(mp.find(mod)!=mp.end()){
                   cnt+=mp[mod];
                   mp[mod]++;
               }
               else{
                 mp[mod]=1;
               }
        }
        return cnt;
    }
};
