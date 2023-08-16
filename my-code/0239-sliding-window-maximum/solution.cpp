class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq; 
        
        for (int i = 0; i < nums.size(); i++) {
            // Remove indices that are out of the current window
            while (!dq.empty() && dq.front() < i - k + 1) {
                dq.pop_front();
            }
            
            // Remove smaller elements from the back of the deque
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            
            dq.push_back(i); // Add current index to the deque
            
            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]); // Maximum of current window
            }
        }
        
        return ans;
    }
};

