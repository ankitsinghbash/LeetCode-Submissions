class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        set<int> Set;
        for(int i=0;i<nums.size();i++)
        {
            Set.insert(nums[i]);
        }
        int idx=0;
        for(auto x : Set)
        {
            nums[idx]=x;
            idx++;
        }
       
         return Set.size();
        
    }
    
};
