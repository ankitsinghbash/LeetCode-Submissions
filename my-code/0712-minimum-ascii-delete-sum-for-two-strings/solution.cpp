class Solution {
public:
    int dp[1010][1010];
    int recur(int i, string& a, int j, string &b) {
        // Both the strings are empty, so the cost is 0
        if(i == a.size() && j == b.size())
            return  0;
        
        // String a is empty, so to make it equal to string b,
        // we have to delete the remaining b string's character
        if(i == a.size()) {
            int res = 0;
            for(int k = j; k < b.size(); k++)
                res += (b[k] - 'a' + 97);

            return res;
        }
        
        // String b is empty, so to make it equal to string a,
        // we have to delete the remaining a string's character
        if(j == b.size()) {
            int res = 0;
            for(int k = i; k < a.size(); k++)
                res += (a[k] - 'a' + 97);
            return res;
        }
        
        
        // Cache check
        if(dp[i][j] != -1)
            return dp[i][j];
        
        // If we both are equal, it is best to go to the next character to delete in their respective strings
        if(a[i] == b[j])
            return dp[i][j] = recur(i + 1, a, j + 1, b);
        // Else either delete in string a or string b, and take the minimum cost to it.
        else
            return dp[i][j] = min((a[i] - 'a') + 97 + recur(i + 1, a, j, b), (b[j] - 'a') + 97 + recur(i, a, j + 1, b));
        
        
    }
    
    int minimumDeleteSum(string s1, string s2) {
        memset(dp, -1, sizeof(dp));
        return recur(0, s1, 0, s2);
    }
};
