class Solution {
public:
    //https://redquark.org/leetcode/0015-3-sum/          approach:
    vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> mainans;
    sort(nums.begin(),nums.end());
    for(int i=0;i<nums.size();i++)
    {
        //remove duplicaty:
        if(i>0&&nums[i]==nums[i-1])   //we remove this condition by usiing set:
        {
            continue;
        }
        int j=i+1;
        int k=nums.size()-1;
        while(j<k)
        {
            
           if(nums[i]+nums[j]+nums[k]==0)
           {
              vector<int> ans;
              ans.push_back(nums[i]);
              ans.push_back(nums[j]);
              ans.push_back(nums[k]);
              mainans.push_back(ans);
              j++;
              while(j<k&&nums[j]==nums[j-1])   //we also use set:
              {
               j++; //remove j ki duplicaty:
              }
           }
           else if(nums[i]+nums[j]+nums[k]<0)
           {
               //array sort the total < 0 required zero hai mean j++;
               j++;
           }
           else
           {
               k--;
           }
        }

    }
    return mainans;
    }
};






