class Solution {
public:
    vector<int> v;
    int n;
    Solution(vector<int>& nums) {
        v=nums;
        n=nums.size();
    }
    
    int pick(int target) {
      int idx=rand()%n;
      while(v[idx]!=target){
          idx = rand()%n;
      }
      return idx;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
