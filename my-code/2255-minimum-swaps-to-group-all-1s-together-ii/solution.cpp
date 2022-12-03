class Solution {
public:
    int minSwaps(vector<int>& nums) {
    
      vector<int> v{nums.begin(),nums.end()};
      for(int i=0;i<nums.size();i++)
      {
          v.push_back(nums[i]);
      }

      int ct1=0;
      for(int i=0;i<nums.size();i++)
      {
          if(nums[i]==1)
          {
              ct1++;
          }
      }

      int left=0;
      int right=ct1-1;

      int current1=0;
      for(int i=left;i<=right;i++)
      {
          if(nums[i]==1)
          {
              current1++;
          }
      }

      int maxx=current1;
      int m=v.size();
      
      int n=nums.size();
      while(left<n)
      {
           right++;
           if(v[right]==1)
           {
               current1++;
           }
           left++;
           if(v[left-1]==1)
           {
               current1--;
           }
        
           maxx=max(maxx,current1);
      }
      int ans = ct1-maxx;
      return ans;
      



    }
};
