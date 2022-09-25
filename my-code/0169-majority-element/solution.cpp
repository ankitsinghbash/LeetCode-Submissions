class Solution {
public:
    int majorityElement(vector<int>& nums) {
          unordered_map<int,int > mp;
    int n=nums.size();
    for(int i=0;i<n;i++)
    {
        mp[nums[i]]++;
    }
    
    
    //after puting the value int map:
    int mini=INT_MIN;
    unordered_map<int,int> :: iterator it;
    for(it=mp.begin();it!=mp.end();it++)
    {
        if((*it).second>mini)
        {
            mini=(*it).second;
        }
    }
    
    //mini is the max value;
    for(it=mp.begin();it!=mp.end();it++)
    {
        if((*it).second==mini)
        {
           int ans=(*it).first;
            return ans;
        }
    }
        
        
        return -1;
    }
   
};
