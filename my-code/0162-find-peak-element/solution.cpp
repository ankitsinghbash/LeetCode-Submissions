class Solution {
public:
    int findPeakElement(vector<int>& nums) {
   
        vector<int> second(nums.begin(),nums.end());
        sort(second.begin(),second.end());
        int n=second.size();
        int val = second[n-1];
        
        //find val in nums and return index:
        for(int i=0;i<nums.size();i++)
        {
            if(val==nums[i])
            {
                return i;
            }
        }
        return -1;

    }
};
