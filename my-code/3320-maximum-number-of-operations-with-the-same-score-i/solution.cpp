class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int cnt=1;
        int val = nums[0]+nums[1];
        for(int i=2;i<nums.size();i=i+2){
            if(i+1<nums.size()){
             int data = nums[i]+nums[i+1];
             if(data==val){
                 cnt++;
             }
             else{
                 break;
             }
            }
        }
        return cnt;
    }
};
