class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int cnt=0;
        int start =0;
        int j=0;
        int maxx = 0;
        while(j<nums.size()){
            if(nums[j]==0){
                cnt++;
            }
            if(cnt>1){
                int value = j-start-1;
                maxx = max(maxx,value);
                cnt=1;
                while(nums[start]!=0){
                    start++;
                }
                start=start+1;
            } 
            j++;
        }
        int value = nums.size();
        maxx = max(value-start-1,maxx);
        return maxx;
    }
};
