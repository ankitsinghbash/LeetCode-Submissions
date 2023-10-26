class Solution {
public:
    const int mod = 1e9+7;
    int numFactoredBinaryTrees(vector<int>& arr){
        int n = arr.size();
        sort(arr.begin(),arr.end());

        unordered_map<int,int> mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]] = i;
        }

        vector<int> dp(n,1);
        for(int i=1;i<n;i++){
            int val = arr[i];
            for(int j=i-1;j>=0;j--){
                if(val%arr[j]==0){
                   int prev = val/arr[j];
                   if(mp.find(prev)!=mp.end()){
                         dp[i] = ((dp[i]%mod)+(1LL*dp[j]*dp[mp[prev]])%mod)%mod;  //1LL change operation from 32 bit to 64 range which range is -9.2 quintillian to +9.2 quintillian:
                   }
                }
            }
        }

        int total=0;
        for(int i=0;i<n;i++){
            total=(total%mod+dp[i])%mod;
        }
        return total;
    }
};
