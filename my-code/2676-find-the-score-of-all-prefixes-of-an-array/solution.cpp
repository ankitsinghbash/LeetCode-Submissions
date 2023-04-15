class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        vector<long long> ans;
        int maxx=0;
        for(int i=0;i<nums.size();i++){
            
            maxx=max(maxx,nums[i]);
            long long value = nums[i]+maxx;
            ans.push_back(value);
        }
        
        //now find the prefinx of the ans;
        vector<long long> real_ans;
        long long sum=0;
        for(int i=0;i<ans.size();i++){
            sum+=ans[i];
            real_ans.push_back(sum);
        }
        return real_ans;
    }
};
