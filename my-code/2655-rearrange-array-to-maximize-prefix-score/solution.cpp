class Solution {
public:
    int maxScore(vector<int>& nums) {
       sort(nums.begin(),nums.end(),greater<int>());
       vector<long long> prefix(nums.size());
       prefix[0]=nums[0];
       
       int cnt=0;
       if(prefix[0]>0){
           cnt++;
       }
       for(int i=1;i<nums.size();++i){
           prefix[i]=prefix[i-1]+nums[i];
           if(prefix[i]>0){
               cnt++;
           }
       }
        return cnt;
        
    }
};
