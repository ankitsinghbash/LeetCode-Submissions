class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0;
        int j=nums.size()-1;
        int maxx = INT_MIN;
        while(i<j){
            int val=nums[i]+nums[j];
            maxx=max(maxx,val);
            i++;
            j--;
        }
        return maxx;
    }
};
