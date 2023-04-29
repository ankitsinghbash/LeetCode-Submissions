class Solution {
public:
    int sum=0;
    int maximizeSum(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
       
        while(k--){
            int val = pq.top();
            pq.pop();
            sum+=val;
            pq.push(val+1);
        }
        return sum;
         
    }
};
