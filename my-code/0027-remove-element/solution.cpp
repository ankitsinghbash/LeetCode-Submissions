class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        //value ko vector se delete kar do:
        //now return the size of the vector:
        vector<int> v;
       for(int i=0;i<nums.size();i++)
      {
        if(nums[i]!=val)
        {
          v.push_back(nums[i]);
        }
        }
       nums=v;
        return nums.size();
    }
};
