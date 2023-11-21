class Solution {
public:
    const long long mod = 1e9+7;
    int reverse_num(int x){
        int number=0;
        while(x!=0){
            int rem = x%10;
            number =number*10 + rem;
            x = x/10;
        }
        return number;
    }

    int countNicePairs(vector<int>& nums) {
    
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            int val = nums[i]-reverse_num(nums[i]);
            mp[val]++;
        }

        long long int total=0;
        for(auto it = mp.begin();it!=mp.end();it++){
            int data = it->second;
            int n = data-1;
            total = (total + static_cast<long long>(n)*(n+1)/2)%mod;
        }
     
       return total%mod;
 
       

    }
};
