class Solution {
public:
    int result=0;
    void solve(int i,vector<int> &nums,int k ,unordered_map<int,int> &mp){
         if(i==nums.size()){
            result++;
            return;
           
         }

        
      
        solve(i+1,nums,k,mp);
        if(!mp[nums[i]-k] && !mp[nums[i]+k]){ //not present hai:
             mp[nums[i]]++;
             solve(i+1,nums,k,mp);
             mp[nums[i]]--;
        }
        

       
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        solve(0,nums,k,mp);
        return result-1;
    }
};


