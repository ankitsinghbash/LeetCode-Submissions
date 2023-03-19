class Solution {
public:
    long long findScore(vector<int>& nums) {

        int n = nums.size();
        map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
     
        long long ans = 0;
        vector<bool> visited(n,false);
        for(auto &x : mp){
            for(auto &i : x.second){
                if(visited[i]==false){
                    ans+=x.first;
                    visited[i]=true;
                    visited[max(i-1,0)]=true;
                    visited[min(i+1,n-1)]=true;
                }
            }
        }
        return ans;

    }
};
