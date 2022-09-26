class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
       vector<int> nums1;
       int counter=0;  //count the number of zeros;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                counter++;
            }
            else
            {
                nums1.push_back(nums[i]);   //when nums[i]!=0;
            }
        }
        
        while(counter!=0)
        {
            nums1.push_back(0);
            counter--;
        }
        
        for(int i=0;i<nums1.size();i++)
        {
            nums[i]=nums1[i];
        }
        
    }
};
