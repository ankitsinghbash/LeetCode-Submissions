class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        vector<int> ans; //ans wali vector:
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        
        int sizes = nums.size();
        int times = sizes/3;
        
        //print element jiska count time se more hai:
        unordered_map<int,int> :: iterator it;
        for(it=mp.begin();it!=mp.end();it++)
        {
            if((*it).second>times)
            {
                ans.push_back((*it).first);
            }
        }
         
        nums=ans;
      return nums;
    }
};
