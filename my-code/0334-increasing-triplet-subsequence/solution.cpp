class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int a = INT_MAX;
        int b = INT_MAX;
        for(int i=0;i<nums.size();i++){
            int value = nums[i];
            if(value<=a){
                a=value;
            }
            else if(value<=b){
                b=value;
            }
            else{
                return true;
            }
        }
        return false;
    }
};
