class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int counter1=0;
        int counter2=0;
        int first;
        bool flag1=false;
        bool flag2=false;
        for(int i=0;i<nums.size();i++)
        {
            if(counter1==0)
            {
                if(target==nums[i])
                {
                  counter1++;
                  first=i;
                  flag1=true;
                }
            }
            else
            {
                if(target==nums[i])
                {
                    counter2++;
                    flag2=true;
                }
            }
        }
        if(flag1==false&&flag2==false)
        {
            return {-1,-1};
        }
        int second=first+counter2;
        vector<int> ans;
        ans.push_back(first);
        ans.push_back(second);
        return ans;
    }
};
