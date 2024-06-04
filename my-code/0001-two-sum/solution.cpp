class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //O(N*log(N)):
        //10^4*10^2=10^6; that is less:

         int n = nums.size();
         
         //[4]
        //now i try to discuss the brute force approach:
        vector<int> ans;
        for(int i=0;i<n;i++){
            int rest_value  = target-nums[i];
            for(int j=i+1;j<n;j++){
                if(nums[j]==rest_value){
                    ans.push_back(i);
                    ans.push_back(j);
                    break;
                }
            }

        }
        return ans;
    }
};
