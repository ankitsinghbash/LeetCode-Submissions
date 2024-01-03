public class Solution {
    public int minFlips(String target) {
        int n = target.length();
        int[] dp = new int[n];
        dp[0] = (target.charAt(0) == '0') ? 0 : 1;
        
        for (int i = 1; i < n; i++) {
            if (target.charAt(i) == target.charAt(i - 1)) {
                dp[i] = dp[i - 1];
            } else {
                dp[i] = dp[i - 1] + 1;
            }
        }
        
        return dp[n - 1];
    }
}
