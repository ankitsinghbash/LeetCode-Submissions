class Solution {
public:
    void dfs(int u,vector<bool> &visited,unordered_map<int,vector<int>> &adj){
        
            visited[u]=true;
            for(auto &x : adj[u]){
                if(visited[x]==false){
                    dfs(x,visited,adj);
                }
            }
    }
 
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> mp;

        for(int i=0;i<edges.size();i++){
             int u = edges[i][0];
             int v = edges[i][1];

             mp[v].push_back(u);  //direct coming edge:
        }


        for(auto it = mp.begin();it!=mp.end();it++){
               vector<int> vec = it->second;
               cout<<it->first<<"-->";
               for(auto x : vec){
                cout<<x<<" ";
               }
               cout<<endl;
        }

        vector<vector<int>> store;
        for(int i=0;i<n;i++){
              vector<bool> visited(n,false);
              dfs(i,visited,mp);
              vector<int> box;
              for(int j=0;j<n;j++){
                   if(visited[j]==true && j!=i){
                     box.push_back(j);
                   }
              }
              store.push_back(box);
         }
         return store;

    }
};
