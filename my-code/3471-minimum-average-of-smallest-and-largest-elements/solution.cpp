class Solution {
public:
    double minimumAverage(vector<int>& nums) {
            int i=0;
            int j = nums.size()-1;
            sort(nums.begin(),nums.end());
            double mini = INT_MAX;
            while(i<j){
                int value = nums[i]+nums[j];
                double ans = value/2.0;
                mini = min(mini,ans);
                i++; 
                j--;
            }
        return mini;
    }  
};
