typedef long long LL;
class Solution {
public:
   int maxScore(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        LL prefix_sum=0;
        vector<LL> store;
 
        for(int i=0;i<nums.size();i++){
            prefix_sum+=nums[i];
            store.push_back(prefix_sum);
        }

     
        int cnt=0;
        for(auto x: store){
            if(x>0){
                cnt++;
            }
        }
        return cnt;
    }
};
