class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
      if(k<=1) return 0;
     
//Two pointer approach:
//1.Just find product in continues order:
//2.Counter the size of the current arr which product in less then k and add to main count:
//3.If product goes equal to or greater then k then remove first value of product by divided with first element and then recounter the size and also increase left by +1 because we remove over first element add it to main count: 
 
       int product= 1;
        int count = 0;
        int  left = 0;
        for (int i = 0; i < nums.size(); i++)
         {
            product *= nums[i];
            while (product >= k){
             product /= nums[left++];
            }
            count += i - left + 1;
        }
        return count;
    }
};


/*
//dp not work but question has solved with dp try it:
vector<vector<long long>> dp(nums.size(),vector<long long>(nums.size()));
        
        for(int g=0;g<nums.size();g++)
        {
            for(int i=0,j=g;j<nums.size();i++,j++)
            {
                  if(g==0)
                  {
                      dp[i][j]=nums[i];
                  }
                  else if(g==1)
                  {
                      dp[i][j]=nums[i]*nums[i+1];
                  }
                  else
                  {
                      dp[i][j]=nums[i]*dp[i][j-1];
                  }
            }
        }


      int counter=0;
      for(int g=0;g<nums.size();g++)
      {
          for(int i=0,j=g;j<nums.size();i++,j++)
          {
              if(dp[i][j]<k)
              {
                  counter++;
              }
          }
      }
      return counter;

*/
