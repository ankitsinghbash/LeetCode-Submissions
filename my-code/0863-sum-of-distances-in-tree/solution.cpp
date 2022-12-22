
class Solution {
public:
//Hard hai:lol
    vector<vector<int>> graph;
    vector<int> counter, ans;
        
    void dfs(int i, int prev) {
        for(auto u : graph[i]) {
            if(u!=prev){   //condition of no repeating this same element because it is graph:
            dfs(u, i);
            counter[i] += counter[u];
            ans[i] += ans[u] + counter[u];
            }
        }
        counter[i] += 1;
    }

    void dfs2(int i, int n, int prev) {
        for(auto u : graph[i]) {
            if(u != prev){
            ans[u] = ans[i] - counter[u] + n - counter[u];
            dfs2(u, n, i);
            }
        }
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
         graph.resize(n);
         ans.resize(n);
         counter.resize(n);

        for(int i=0;i<n -1;i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        
        dfs(0,-1);
        dfs2(0, n,-1);
        return ans;
    }
};










/*
class Solution {
public:
    vector<vector<int>> v;
    vector<int> counter, res;
        
    void dfs(int i, int p = -1) {
        for(auto u : v[i]) {
            if(u == p) continue;
            dfs(u, i);
            counter[i] += counter[u];
            res[i] += res[u] + counter[u];
        }
        counter[i] += 1;
    }

    void dfs2(int i, int n, int p = -1) {
        for(auto u : v[i]) {
            if(u == p) continue;
            res[u] = res[i] - counter[u] + n - counter[u];
            dfs2(u, n, i);
        }
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        v.resize(n);
        for(int i = 0; i < n - 1; i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            v[a].push_back(b);
            v[b].push_back(a);
        }
        res.resize(n);
        counter.resize(n);
        dfs(0);
        dfs2(0, n);
        return res;
    }
};
*/
