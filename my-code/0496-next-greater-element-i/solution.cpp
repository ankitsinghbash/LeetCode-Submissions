class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
       
       vector<int> ans;

      map<int,int> mp; 
      for(int i=0;i<nums2.size();i++)
      {
          mp[nums2[i]]=i;
      }

      for(int i=0;i<nums1.size();i++)
      {
          int idx = mp[nums1[i]];
          bool flag=true;
          for(int j=idx;j<nums2.size();j++)
          {
              if(nums2[j]>nums1[i])
              {
                  flag=false;
                  ans.push_back(nums2[j]);
                  break;
              }
          }
          if(flag==true)
          {
              ans.push_back(-1);
          }


      }
      return ans;

    }
};


/*Give TLE:

 int binary(int key,vector<int> &nums2,int n)
   {
      int low=0;
	  int high=n-1;
	  while(low<=high)
	  {
		  int mid=(high+low)/2;
		  if(nums2[mid]==key)
		  {
			  return mid;
		  }
		  else if(key<nums2[mid])
		  {
			  high=mid-1;
		  }
		  else
		  {
			  low=mid+1;
		  }
	  }
      return -1;
   }


      vector<int> ans;
        for(int i=0;i<nums1.size();i++)
        {
            int val = nums1[i];
            //idx of val in the nums2;
            int n=nums2.size();
            int idx = binary(val,nums2,n);
            int j = idx+1;
            bool flag=true;
            while(j!=n)
            {
               if(nums2[j]>val)
               {
                   flag=false;
                   ans.push_back(nums2[j]);
                   break;
               }
            }
            if(flag==true)
            {
                ans.push_back(-1);
            }
        }
        return ans;
        */
