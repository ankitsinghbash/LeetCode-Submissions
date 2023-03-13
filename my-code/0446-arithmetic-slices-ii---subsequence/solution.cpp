class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        long long int ans = 0 ;
        vector<unordered_map<long long int,long long int>> mp(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                long long int diff = (long long int)nums[i]-nums[j];
                auto it=mp[j].find(diff);
                if(it!=mp[j].end()){
                      ans += mp[j][diff];  //or ans+=it->second;
                }
                else{
                    ans+=0;
                }
                mp[i][diff]+=mp[j][diff]+1;  //+1 khud hua isslyia:
            }
        }
        return ans;
    }
};
