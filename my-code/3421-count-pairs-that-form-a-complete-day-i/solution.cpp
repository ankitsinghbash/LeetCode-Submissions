class Solution {
public:
    int countCompleteDayPairs(vector<int>& nums) {
        //brute force:
        int cnt=0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j = i+1;j<n;j++){
                if((nums[i]+nums[j])%24==0){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
