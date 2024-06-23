class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
          int n = nums.size();
           vector<int> ans;
           deque<int> dq;   //deque adjust like front give maximum and back give minimum:
           for(int i=0;i<n;i++){
                    while(!dq.empty() && dq.front()<i-k+1){
                        dq.pop_front();
                    }

                    while(!dq.empty() && nums[dq.back()]<=nums[i]){
                        dq.pop_back();
                    }
                    dq.push_back(i);   //0
                    if(i>=k-1){
                         ans.push_back(nums[dq.front()]);
                    }
           }
           return ans;

    }
};



