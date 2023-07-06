class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
       int sum=0;
       for(auto x : nums){
           sum+=x;
       }
       if(sum<target){
           return 0;
       }



        int result = INT_MAX;
        int start =0;
        int j=0;
        int total=0;
        while(j<nums.size()){
            total+=nums[j];
            if(total>=target){
                while(total>=target && start<nums.size()){
                    total-=nums[start];
                    start++;
                }
                int value  = j-start+2;
                 result = min(result,value);
            }
            j++;
        }
       
        if(result!=INT_MAX){
            return result;
        }
        return 0;
    }
};
