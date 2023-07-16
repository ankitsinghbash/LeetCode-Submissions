class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        int mask = -1;
        map<int,int> mp;
        int total_value = 0;
        for(auto x : nums){
            mp[x]++;
            if(mp[x]>(n/2)){
                mask = x;
                total_value = mp[x];
            }
        }
        
        int counter=0;
        for(int i=0;i<n;i++){
            if(nums[i]==mask){
                counter++;
            }
            if(counter*2>(i+1) && (total_value-counter)*2 > (n-(i+1))){
                return i;
            }
        }
        return -1;
    }
};
