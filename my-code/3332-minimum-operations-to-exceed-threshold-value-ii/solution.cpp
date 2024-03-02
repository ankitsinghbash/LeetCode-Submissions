class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        
        int cnt=0;
        
        while(pq.size()>=2 && pq.top()<k){
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();
            
            long long val1 = min({(long long)first, (long long)second})*2;
            long long val2 = max({(long long)first, (long long)second});
            long long total = val1+val2;
            
            pq.push(total);
            cnt++;
        }
        
        // if (!pq.empty() && pq.top() < k)
        //     cnt++;
        
        return cnt;
    }
};
