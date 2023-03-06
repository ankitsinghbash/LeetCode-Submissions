class Solution {
public:
    int maxCount(vector<int>& nums, int n, int maxSum) {
        unordered_map<int,int> mp;
        for(auto &x : nums){
            mp[x]++;
        }
        
        vector<int> ans;
        int i=1;
        while(i<=n){
            auto it = mp.find(i);
            if(it==mp.end()){
                 ans.push_back(i);
            }
            i++;
        }
    
        for(auto &x : ans){
            cout<<x<<" ,"; 
        }
    
        int cnt=0;
        int sum=0;
        for(int i=0;i<ans.size();++i){
            sum+=ans[i];
            if(sum>maxSum){
                return cnt;
            }
            cnt++;
        }
        return ans.size();
    }
};
