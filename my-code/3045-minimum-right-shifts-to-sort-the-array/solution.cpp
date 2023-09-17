class Solution {
public:
    
bool ispossible(vector<int> &nums,int min_idx){
    int n = nums.size();
    for(int i=0;i<=n-2;i++){
      int curr = nums[(i+min_idx)%n];
      int next = nums[(i+min_idx+1)%n];
      if(curr>next){
        return false;
      }
    }
    return true;
}

    int minimumRightShifts(vector<int>& nums) {
        //ispossible:
        int n = nums.size();
        int min_idx;
        int mini = *min_element(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
          if(nums[i]==mini){
            min_idx = i;
            break;
           }
         }
        
       if(ispossible(nums,min_idx)==false){
        return -1;
      }
        int maxx = *max_element(nums.begin(),nums.end());
        int max_idx;
        for(int i=0;i<n;i++){
            if(nums[i]==maxx){
                max_idx = i;
                break;
            }
        }
        
        return n - max_idx -1;
        
    }
};
