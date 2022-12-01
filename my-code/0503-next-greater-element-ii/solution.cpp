class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
          int val = nums[i];
          int j=i+1;
          bool flag=true;
          while(j!=nums.size())
          {
             if(nums[j]>nums[i])
             {
                 flag=false;
                 ans.push_back(nums[j]);
                 break;
             }
             j++;
          }


          int k=0;
          bool flag2=true;
          if(flag==true)
          {
            while(k<i)
            {
              if(nums[k]>nums[i])
              {
                  flag2=false;
                  ans.push_back(nums[k]);
                  break;
              }
              k++;
            }
          }
          if(flag==true&&flag2==true)
          {
              ans.push_back(-1);
          }

        }
       return ans; 
    }
};
