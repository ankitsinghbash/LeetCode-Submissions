class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int size=nums.size(); //is the given range:
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        vector<int> ans;
        //now range start from 1 to n=size;
        for(int i=1;i<=nums.size();i++)
        {
            //check i is present of not in the range:
            if(mp.find(i)==mp.end())
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
