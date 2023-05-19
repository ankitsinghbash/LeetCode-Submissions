//Method 1: BFS
class Solution {
public:
   
   bool BFS(int curr_node,int curr_color,unordered_map<int,vector<int>> &adj,vector<int> &color){
      queue<int> qu;
      qu.push(curr_node);
      color[curr_node]=curr_color;
    
      while(!qu.empty()){
         int size = qu.size();
         while(size--){
             int u = qu.front();
             qu.pop();
             for(auto &v : adj[u]){
                 if(color[v]==color[u]){
                     return false;
                 }
                 else if(color[v]==-1){
                     color[v]=1-color[u];
                     qu.push(v);
                 }
             }
         }
      }
      return true;
   }



    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[i].size();j++){
                int v = graph[i][j];

                adj[i].push_back(v);
            }
        }


        vector<int> color(V,-1);   //also work as a visited:
        for(int i=0;i<V;i++){
            if(color[i]==-1){
                if(BFS(i,0,adj,color)==false){
                    return false;
                }
            }
        }
       return true;
    }
};

//Method 2: DFS
// class Solution {
// public:
   
//    bool dfs(int curr_node,int curr_color,unordered_map<int,vector<int>> &adj,vector<int> &color){
//       if(color[curr_node]!=-1) return true;

//       color[curr_node] = curr_color;
//       for(auto &v : adj[curr_node]){
//           if(color[v]==color[curr_node])return false;
//           else if(color[v]==-1){
//               int color_v = 1-color[curr_node];
//               if(dfs(v,color_v,adj,color)==false){
//                   return false;
//               }
//           }
//       }
//       return true; 
//    }

//     bool isBipartite(vector<vector<int>>& graph) {
//         int V =  graph.size();

//         unordered_map<int,vector<int>> adj;
//         for(int i=0;i<graph.size();i++){
//             for(int j=0;j<graph[i].size();j++){
//                 int v = graph[i][j];

//                 adj[i].push_back(v);
//             }
//         }

//         vector<int> color(V,-1);
//         for(int i=0;i<V;i++){
//             if(color[i]==-1){
//                 if(dfs(i,0,adj,color)==false){
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }
// };
