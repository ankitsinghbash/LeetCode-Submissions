class Solution {
public:
    vector<string> ans;
    vector<string> summaryRanges(vector<int>& nums) {
       
       long long i=0;
       while(i<nums.size()){
           long long start = i;
           while(start+1<nums.size() && nums[start+1]==nums[start]+1){
               start++;
           }
           string str1 = to_string(nums[i]);
           string str2 = to_string(nums[start]);
           if(str1==str2){
               ans.push_back(str1);
           }
           else{
              string s = str1+"->"+str2;
              ans.push_back(s);
           }
           i=start;
           i++;
       }
       return ans;
    }
};
