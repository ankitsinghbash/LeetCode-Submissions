class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) 
    {
        vector<int>nums1=nums;
        sort(nums1.begin(),nums1.end(),greater<int>());
        unordered_map<int,int>large;
        for(int i=0; i<k; i++) ++large[nums1[i]];
        vector<int>ans;
        for(int i=0; i<nums.size(); i++)
        {
            if(k>0 && large[nums[i]]!=0)
            {
                ans.push_back(nums[i]);
                --large[nums[i]];
                --k;
            }
            else if(k<0)
                break;
        }
        return ans;
    }
};
