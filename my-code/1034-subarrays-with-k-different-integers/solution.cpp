class Solution {
public:
    int solve(vector<int> &nums,int k){
        //easy for find k = find upto k subtract upto k-1:
        int counter=0;
        unordered_map<int,int> mp;
        int right=0;
        int left=0;
        while(right<nums.size()){
                mp[nums[right]]++;
                while(mp.size()>k){
                    mp[nums[left]]--;
                    if(mp[nums[left]]==0){
                        mp.erase(nums[left]);
                    }
                    left++;
                }
                counter+=right-left+1;
                right++;
        }
        return counter;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
    }
};
