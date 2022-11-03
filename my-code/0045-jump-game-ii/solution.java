class Solution {
    public int jump(int[] arr) {
        int dp[] = new int[arr.length];

        // dp[arr.length-1] = ;

        for(int idx = arr.length-2 ; idx >=0 ; idx--){
            int steps = arr[idx];
        
            int min = Integer.MAX_VALUE;
            if(steps > 0){
                for(int i = 1 ; i <= steps ;i++){
                    if(idx + i < arr.length)
                        min = Math.min(min,dp[idx+i]);
                }
            }
            dp[idx] = min == Integer.MAX_VALUE ? min : min+1;
          
        }
        return dp[0];
    }
}
