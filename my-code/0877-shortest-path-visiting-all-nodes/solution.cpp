#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int target = (1 << n) - 1;
        queue<pair<int, int>> q; // {node, bitmask}
        vector<vector<bool>> visited(n, vector<bool>(1 << n, false));

        // Initialize the queue with all nodes as starting points
        for (int i = 0; i < n; ++i) {
            q.push({i, 1 << i});
            visited[i][1 << i] = true;
        }

        int steps = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto [node, bitmask] = q.front();
                q.pop();
                if (bitmask == target) // All nodes have been visited
                    return steps;
                for (int neighbor : graph[node]) {
                    int new_bitmask = bitmask | (1 << neighbor);
                    if (!visited[neighbor][new_bitmask]) {
                        q.push({neighbor, new_bitmask});
                        visited[neighbor][new_bitmask] = true;
                    }
                }
            }
            ++steps;
        }
        return -1; // Should not reach here
    }
};

