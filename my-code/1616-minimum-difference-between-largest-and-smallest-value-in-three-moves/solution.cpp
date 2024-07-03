class Solution {
public:
    int minDifference(vector<int>& nums) {
      int n = nums.size();
      //0th index - n-4th index:   (n-1,n-2,n-3 index converted to minimum value)
      //1th index - n-3th index:   (n-2,n-1 index converted to minimum value)
      //2th index - n-2th index:   (0,1 and n-1 converted to minimum value)
      //3th index - n-1th index:   (0,1,2 are converted to minimum value)
      if(n<=3){
        return 0;
      }

      sort(nums.begin(),nums.end());

      int mini = INT_MAX;
      for(int i=0;i<=3;i++){
         int start = nums[i];
         int end = nums[n+i-4];
         int diff = abs(end-start);
         mini = min(diff,mini);
      }
      return mini;


    }
};

//0,1,5,10,14
