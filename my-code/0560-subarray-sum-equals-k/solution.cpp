class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int target = k;
        int counter=0;
        int currsum=0;
        for(int i=0;i<nums.size();i++){
            currsum+=nums[i];
            if(currsum==target){
                counter++;
            }
            if(mp.find(currsum-target)!=mp.end()){
                counter+=mp[currsum-target];
            }
            mp[currsum]++;
        }
        return counter;
    }
};
