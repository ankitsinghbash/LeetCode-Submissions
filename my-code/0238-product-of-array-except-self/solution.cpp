class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //Most optimal O(1) space with no division with O(n):
        int n = nums.size();
        vector<int> prefix_prod(n,1);
        for(int i=1;i<n;i++){
             prefix_prod[i] = prefix_prod[i-1]*nums[i-1];
        }
    
        int right=1;
        for(int i=n-1;i>=0;i--){
            prefix_prod[i] = prefix_prod[i]*right;
            right=right*nums[i];
        }
        return prefix_prod;

    }
};
