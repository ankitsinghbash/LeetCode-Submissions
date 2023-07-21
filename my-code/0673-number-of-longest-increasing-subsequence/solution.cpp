class Solution {
public:
    pair<int, int> solve(int idx, int prev, vector<int>& nums,vector<vector<pair<int,int>>> &dp) {
        if (idx > nums.size()) {
            pair<int, int> p = {0, 1};
            return p;
        }

        if(dp[idx][prev].first !=-1){
            return dp[idx][prev];
        }

        pair<int, int> notpick = {0, 0};
        pair<int, int> pick = {0, 0};
        notpick = solve(idx + 1, prev, nums,dp);
        if (prev == 0 || nums[idx-1] > nums[prev-1]) {
            pick = solve(idx + 1, idx, nums,dp);
            pick.first++;
        }

        if (pick.first == notpick.first) {
            pair<int, int> v = {pick.first, pick.second + notpick.second};
            return dp[idx][prev] = v;
        } else if (pick.first > notpick.first) {
            return dp[idx][prev] = pick;
        } else {
            return dp[idx][prev] = notpick;
        }
    }

    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
       vector<vector<pair<int, int>>> dp(n + 1, vector<pair<int, int>>(n+1, {-1, -1}));
        return solve(1, 0, nums,dp).second;
    }
};

