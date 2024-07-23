class Solution {
public:
    bool check(int u,unordered_map<int,vector<int>> &adj,vector<int> color){


  
         queue<int> qu;
         qu.push(u);
         color[u]=0;
         while(!qu.empty()){
             int size = qu.size();
             while(size--){
                int u = qu.front();
                qu.pop();
                for(auto &v : adj[u]){
                     if(color[v]==color[u]){
                        return false;
                     }
 
                    if(color[v]==-1){
                        //not visited means visited it:
                        qu.push(v);
                        color[v] = 1-color[u];
                    }
                }
             }
         }
       

        return true;



    }

    bool isBipartite(vector<vector<int>>& graph) {
           //check graph is bipartite or not using bfs algorithm:
           unordered_map<int,vector<int>> adj;
           int n = graph.size();
           for(int i=0;i<n;i++){
                 for(int j=0;j<graph[i].size();j++){
                    adj[i].push_back(graph[i][j]);
                 }
           }


           //now using color vector for coloring as well for checking visited the node:
           int V = n;
           vector<int> color(V,-1);

           for(int i=0;i<V;i++){
               if(color[i]==-1 && check(i,adj,color)==false){
                  return false;
               }
           }

           return true;
    }
};
