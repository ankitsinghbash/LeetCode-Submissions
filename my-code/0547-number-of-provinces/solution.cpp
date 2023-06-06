class Solution {
public:
   void dfs(int u,unordered_map<int,vector<int>> &adj,vector<bool> &visited){
      if(visited[u]==true) return;

      visited[u]=true;
      for(auto &v : adj[u]){
          if(visited[v]==false){
              dfs(v,adj,visited);
          }
      }
   }




    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected[0].size();j++){
                if(i!=j && isConnected[i][j]==1){
                    adj[i].push_back(j);
                }
            }
        }

        int n = isConnected.size();
        vector<bool> visited(n,false);
        int cnt = 0;
        for(int i=0;i<n;i++){
             if(visited[i]==false){
                 cnt++;
                 dfs(i,adj,visited);
             }
        }
        return cnt;
    }
};
