class Solution
 {
      public:
       vector<int> smallerNumbersThanCurrent(vector<int>& nums)
        {
             int n=nums.size(),i,j,k;
              vector<int>c; for(i=0;i<n;i++)
               {
                   k=0;
                    for(j=0;j<n;j++) 
                    { 
                    if((i!=j)&&(nums[i]>nums[j]))
                     { 
                         k++; 
                     }
                     }
                   c.push_back(k);
                } 
                return c;
         }
 };
