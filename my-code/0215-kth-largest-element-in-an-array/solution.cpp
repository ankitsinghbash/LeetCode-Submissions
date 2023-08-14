class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //
        priority_queue<int> pq;
        for(auto x : nums){
            pq.push(x);
        }
          
        int value;
        while(k--){
            value = pq.top();
            pq.pop();
        }
        return value;

    }
};
