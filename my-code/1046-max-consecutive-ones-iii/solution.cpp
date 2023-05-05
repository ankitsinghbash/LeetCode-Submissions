class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxx = 0;
        int left = 0;
        int cnt =0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                cnt++;
            }

            while(cnt>k){
                if(nums[left]==0){
                    cnt--;
                }
                left++;
            }
 
            maxx = max(maxx,i-left+1);
        }
        return maxx;
    }
};
