class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.size();
        vector<int> dp(26,0);
        for(int i=0;i<n;i++){
                int curr = s.at(i)-'a';
                int lowest = max(0,curr-k); //left adjacent of current character:
                int highest = min(25,curr+k);//right adjacent of current character:
                int longest=0;
                for(int j = lowest;j<=highest;j++){    //find maximum for left to right wale ki length:
                    longest = max(longest,dp[j]);
                }
                dp[curr] = max(dp[curr],longest+1);   //update dp to put maxx length:
        }

        auto maxx = *max_element(dp.begin(),dp.end());
        return maxx;
    }
};
