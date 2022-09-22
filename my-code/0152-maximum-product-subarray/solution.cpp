class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int ans=nums[0];
        int maxi = ans;
        int mini = ans;
        
        int n=nums.size();
        for(int i=1;i<n;i++)
        {
            if(nums[i]<0)
            {
                swap(maxi,mini);
            }
            maxi=max(nums[i],nums[i]*maxi);
            mini=min(nums[i],nums[i]*mini);
            ans=max(maxi,ans);
        }
        return ans;
    }
};
