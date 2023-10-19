class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        queue<int>q;
        vector<int>indegree(n);
        vector<vector<int>>adj(n);
        for(int i = 0;i < relations.size();i++){
            int u = relations[i][0] - 1;
            int v = relations[i][1] - 1;
            adj[u].push_back(v);
            indegree[v]++;
        }
        // for(int i = 0;i < n;i++){
        //     cout << i << ": ";
        //     for(int j = 0;j < adj[i].size();j++){
        //         cout << adj[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        for(int i = 0;i < n;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int>ans(n);
        for(int i = 0;i < n;i++){
            ans[i] = time[i];
        }
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(auto node : adj[u]){
                ans[node] = max(ans[node],ans[u] + time[node]);
                indegree[node]--;
                if(indegree[node] == 0){
                    q.push(node);
                }
            }
        }
        return *max_element(ans.begin(),ans.end());
    }
};
