class Solution {
public:
    bool search(vector<int>& nums, int target) {
        //use binary search tree on sorted arr;
        sort(nums.begin(),nums.end());
        //now nums is sorted;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                return true;
            }
        }
        return false;


    }
};
