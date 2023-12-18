class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int maxx=INT_MIN;
        int second_maxx = INT_MIN;
        int mini = INT_MAX;
        int second_mini = INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxx){
                second_maxx = maxx;
                maxx = nums[i];
            }
            else{
                second_maxx = max(second_maxx,nums[i]);
            }
            if(nums[i]<mini){
                second_mini = mini;
                mini = nums[i];
            }
            else{
                second_mini = min(second_mini,nums[i]);
            }
        }
        int val = maxx*second_maxx-mini*second_mini;
        return val;
    }
};
