class Solution {
public:
    int reductionOperations(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       int type=0;
       int answer=0;
       for(int i=1;i<nums.size();i++){
           if(nums[i]!=nums[i-1]){
                   type++;
           }
           answer+=type;
       }
       return answer;
    }
};
