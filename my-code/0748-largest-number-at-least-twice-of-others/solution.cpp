class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        vector<int> check(nums.begin(),nums.end());
        sort(check.begin(),check.end());
        int mynum = check[check.size()-1];
        
        int actual = check.size()-2;
        for(int i=0;i<=actual;i++)
        {
            if(check[i]*2>mynum)
            {
                return -1;
            }
        }
  
       //nums me mynum ka index do;
       for(int i=0;i<nums.size();i++)
       {
           if(mynum==nums[i])
           {
               return i;
           }
       }
      return 0;


    }
};
