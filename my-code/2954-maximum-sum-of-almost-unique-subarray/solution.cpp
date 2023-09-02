

class Solution {
public:
    typedef long long ll;
    long long maxSum(vector<int>& nums, int m, int k) {
        //sliding window:
        ll maxx_sum=0;
        ll curr_sum=0;
        unordered_map<int,int> mp;
        for(int i=0;i<k;i++){
           mp[nums[i]]++;
           curr_sum+=nums[i]; 
        }
        int mp_size = mp.size();
        int x = k-mp_size;
        if(mp_size>=m){
            maxx_sum=max(maxx_sum,curr_sum);
        }
        
        for(int i=k;i<nums.size();i++){
            int prev = nums[i-k];
            curr_sum-=prev;
            mp[prev]--;
            if(mp[prev]==0){
                mp.erase(prev);
            }
            int new_value = nums[i];
            curr_sum+=new_value;
            mp[new_value]++;
            int mps = mp.size();
            int y=k-mps;
            if(mps>=m){
                maxx_sum=max(maxx_sum,curr_sum);
            }
        }
        return maxx_sum;
        
    }
};
