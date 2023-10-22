class Solution {
public:
    typedef pair<int,int> P;
   
 struct cmp {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b){
        if (a.first == b.first) {
            return a.second<b.second; 
        } else {
            return b.first>a.first;  
        }
    }
};

    int constrainedSubsetSum(vector<int>& nums, int k) {
        priority_queue<P,vector<P>,cmp> pq;
        int result = -1;
        
        vector<int> dp(nums.size());
        for(int i=0;i<nums.size();i++){
            dp[i] = nums[i];
        }

   
        pq.push({nums[0],0});
        result = max(result,nums[0]);
        for(int i=1;i<nums.size();i++){
              while(!pq.empty() && i-pq.top().second>k){
                   pq.pop();
                }

                dp[i] = max(dp[i],pq.top().first+nums[i]);
                pq.push({dp[i],i});
                result = max(dp[i],result);
                
        }
        return result;
    }
};
