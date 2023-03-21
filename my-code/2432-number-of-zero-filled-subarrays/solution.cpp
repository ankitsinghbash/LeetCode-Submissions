class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        //second method:
        unordered_map<int,int> mp;
        mp[0]=0;
        long long ans = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                // ans+=mp[0];
                 mp[0]++;
                  ans+=mp[0];
            }
            else{
                mp[0]=0;
            }
        }
        return ans;
    }
};
