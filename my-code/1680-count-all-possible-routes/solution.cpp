class Solution {
public:
   int dp[101][201];
   
   int dfs(int start, int finish, int fuel, vector<int> &locations, unordered_map<int, vector<int>> &adj) {
     if (fuel < 0) {
         return 0;
     }
  
     int cnt = 0;
     if (start == finish) {
         cnt++;
     }

     if (dp[start][fuel] != -1) {
         return dp[start][fuel];
     }

     for (auto next : adj[start]) {
         int less_fuel = abs(locations[start] - locations[next]);
         cnt += dfs(next, finish, fuel - less_fuel, locations, adj);
         cnt %= 1000000007;  // Apply modulo to prevent overflow.
     }
     return dp[start][fuel] = cnt;
   }

    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < locations.size(); i++) {
            for (int j = 0; j < locations.size(); j++) {
                if (i != j) {
                    adj[i].push_back(j);
                }
            }
        }

        memset(dp, -1, sizeof(dp)); // Initialize dp array with -1 using memset.
        return dfs(start, finish, fuel, locations, adj);
    }
};

