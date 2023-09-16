class Solution {
private:
    vector<vector<int>> v;
    
    bool dfs(int i, int j, int mid, int n, int m, vector<vector<int>>& h) {
        if (i == n - 1 && j == m - 1)
            return true;
        
        v[i][j] = 1;
        bool op = false;
        
        if (i > 0 && v[i - 1][j] == 0 && abs(h[i][j] - h[i - 1][j]) <= mid) {
            op = op || dfs(i - 1, j, mid, n, m, h);
        }
        if (j > 0 && v[i][j - 1] == 0 && abs(h[i][j] - h[i][j - 1]) <= mid) {
            op = op || dfs(i, j - 1, mid, n, m, h);
        }
        if (i < n - 1 && v[i + 1][j] == 0 && abs(h[i][j] - h[i + 1][j]) <= mid) {
            op = op || dfs(i + 1, j, mid, n, m, h);
        }
        if (j < m - 1 && v[i][j + 1] == 0 && abs(h[i][j] - h[i][j + 1]) <= mid) {
            op = op || dfs(i, j + 1, mid, n, m, h);
        }
        
        return op;
    }
    
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        int n = h.size();
        int m = h[0].size();
        v.assign(n, vector<int>(m, 0));
        
        int start = 0, end = INT_MAX;
        int ans = INT_MAX;
        
        while (start <= end) {
            for (vector<int>& a : v) {
                fill(a.begin(), a.end(), 0);
            }
            
            int mid = start + (end - start) / 2;
            
            if (dfs(0, 0, mid, n, m, h)) {
                ans = min(ans, mid);
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        
        return ans;
    }
};



