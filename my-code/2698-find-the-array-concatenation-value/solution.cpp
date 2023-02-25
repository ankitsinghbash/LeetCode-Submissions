class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        int low=0;
        int high = nums.size()-1;
        long long ans=0;
        while(low<=high){
            if(low==high){
                ans+=stoi(to_string(nums[low]));
            }
            if(low!=high){
            string start = to_string(nums[low]);
            string end = to_string(nums[high]);
            ans+=stoi(start+end);
            }
            low++;
            high--;
        }
        return ans;
    }
};
