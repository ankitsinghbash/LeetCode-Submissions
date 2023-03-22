class Solution {
public:

   void solve(unordered_map<int,vector<pair<int,int>>> &adj,int &mini,int u,vector<bool> &visited){
       if(visited[u]==true) return;

       visited[u]=true;
       for(pair<int,int> x : adj[u]){
           mini = min(mini,x.second);
           if(!visited[x.first]){
           solve(adj,mini,x.first,visited);
           }
       }
   }
  


    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<pair<int,int>>> adj;
        for(int i=0;i<roads.size();++i){
            int u = roads[i][0];
            int v = roads[i][1];
            int costs = roads[i][2];
            adj[u].push_back({v,costs});
            adj[v].push_back({u,costs});
        }

       vector<bool> visited(n+1,false);
       int mini = INT_MAX;
       solve(adj,mini,1,visited);
       return mini;
    }
};
