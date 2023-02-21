class Solution {
public:
   
   bool dfs(vector<vector<int>> &adj,int curr,vector<int> &color,int currcolor){
        if(color[curr]!=-1) return true;
  
        color[curr]=currcolor;
        for(auto &v : adj[curr]){
            if(color[v]==color[curr]){
                return false;
            }
            else if(color[v]==-1){
                int colorv = 1-color[curr];
                if(dfs(adj,v,color,colorv)==false){
                    return false;
                }
            }
        }
        return true;

   }



    bool isBipartite(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> color(V,-1);
        for(int i=0;i<V;++i){
            if(color[i]==-1){
                if(dfs(adj,i,color,1)==false){
                    return false;
                }
            }
        }
        return true;
    }
};
