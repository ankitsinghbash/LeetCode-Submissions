class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map<int,int> mp;
        //first value store data second one store index;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]=i; //put indexing from 0 to nums.size()-1;
        }
        
        for(int i=0;i<nums.size();i++)
        {
            int b=target-nums[i];
            //check karo b map me hai ki nahi
            //and map me hai to same index me na ho;
            if(mp.find(b)!=mp.end())
            {
                //mean b hai:
                //Now check karo ki same index pe na ho;
                //b ke index map ke index ke equal na ho check karo:
                 if(mp[b]!=i)
                 {
                     return {i,mp[b]};
                 }
            }
        }
        return {-1,-1};
    }
};
