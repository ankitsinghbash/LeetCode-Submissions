#include <vector>
#include <string>

class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;
        vector<int> dp(s.size());
        dp[0] = 1;

        for (int i = 1; i < s.size(); i++) {
            long long total = 0;  // Use long long to handle larger values
           
             for(int j=i-1;j>=0;j--) {
                if (s[i] == s[j]) {
                    continue;
                }
                total = (total + dp[j]) % MOD;
                
            }
            dp[i] = (total + 1) % MOD;
        }

        long long answer = 0;  // Use long long to handle larger values
        for (int i = 0; i < s.size(); i++) {
            answer = (answer + dp[i]) % MOD;
        }

        return static_cast<int>(answer);  // Convert back to int for the result
    }
};
