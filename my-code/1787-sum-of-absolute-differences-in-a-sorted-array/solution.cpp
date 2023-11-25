class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);
        int curr=0;
  
        int sum = accumulate(nums.begin(),nums.end(),0);
 
        for(int i=0;i<n;i++){
            curr+=nums[i];
            prefix[i]=curr;
        }


        vector<int> store(n);
  
        for(int i=0;i<n;i++){
            int forward_i = n-i-1;
            int backward_i = i;
            int right_prefix = sum-prefix[i]-(nums[i]*forward_i);
 
            int left_prefix=0;
            if(i>=1){
              left_prefix =  nums[i]*backward_i - prefix[i-1];
            }

            store[i] = right_prefix+left_prefix;

        }


        return store;

    }
};
