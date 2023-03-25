class Solution {
public:
    
     void dfs(unordered_map<int,vector<int>> &adj,vector<bool> &visited,long long  &cnt,int u){
         if(visited[u]==true) return;
         
         visited[u]=true;
         cnt++;
         for(auto &v : adj[u]){
             if(visited[v]==false){
               //  cnt++;
                 dfs(adj,visited,cnt,v);
             }
         }
     }

    long long countPairs(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<edges.size();++i){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        long long  total = (long long)n*(n-1)/2;

        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            long long cnt = 0;
            dfs(adj,visited,cnt,i);
            total-=cnt*(cnt-1)/2;
        }
        return total;

    }
};
