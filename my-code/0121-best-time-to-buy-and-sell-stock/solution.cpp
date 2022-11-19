class Solution {
public:
  
    int maxProfit(vector<int>& nums) {
        int lowestcostbefore=INT_MAX;
        int profifsoldtoday = 0;
        int maximumpro = 0;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<lowestcostbefore)  //this calculate ki abb takk ka minimum buying cost of stock:
            {
                lowestcostbefore=nums[i];
            }

           profifsoldtoday=nums[i]-lowestcostbefore;
           if(profifsoldtoday>maximumpro)
           {
               maximumpro=profifsoldtoday;
           }

        }
        return maximumpro;
    

    }
};



/*   vector<int> ans;
for(int i=0;i<nums.size()-1;i++)
       {
       for(int j = i+1;j<nums.size();j++)
         {
          if(nums[i]<nums[j])
           {
             int diff = nums[j]-nums[i];
             ans.push_back(diff);
           }
        }
        }

    if(!ans.empty()){
    int result = *max_element(ans.begin(),ans.end());
    return result;
    }
    else
    {
      return 0;
    }

*/
