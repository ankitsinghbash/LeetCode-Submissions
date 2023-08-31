class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
       //adding technique:
       long long cnt=0;
       int n = nums.size();
       int last = nums[n-1];
       for(int i=n-2;i>=0;i--){
           if(nums[i]>last){
              int time = nums[i]/last;
              if(nums[i]%last!=0){
                  time++;
              } 
              last=nums[i]/time;  //most imp dry run for [3,7,3]:
              cnt+=time-1;
             
           }
           else{
               last = nums[i];
           }
       }
       return cnt;
    }
};
