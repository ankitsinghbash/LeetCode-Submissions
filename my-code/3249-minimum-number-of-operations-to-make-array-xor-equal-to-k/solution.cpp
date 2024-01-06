class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
          int start=0;
          int len = nums.size();
          start = start^k;
          for(int i=0;i<len;i++){
                start = start^nums[i];
          }
         
          int val = start;
          int totalway=0;
          while(start!=0){
             int cnt = (start&1);
             totalway = totalway+(cnt);
              start= start>>1;
          }
         return totalway;
          
    }
};
