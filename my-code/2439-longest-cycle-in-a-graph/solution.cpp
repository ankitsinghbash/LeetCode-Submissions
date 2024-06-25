class Solution {
public:
    int ans = -1;
    void dfs(vector<int> &edges,int u,vector<bool> &visited,vector<bool> &inRecurssion,vector<int> &store){
          visited[u]=true;
          inRecurssion[u]=true;
          int v = edges[u];

          if(v!=-1 && visited[v]==false){
              store[v]=store[u]+1;
              dfs(edges,v,visited,inRecurssion,store);
          }
          else if(v!=-1 && visited[v]==true && inRecurssion[v]==true){
               ans=max(ans,store[u]-store[v]+1);
          }
          inRecurssion[u] = false;

    }

    int longestCycle(vector<int>& edges) {
        int V = edges.size();
        vector<bool> visited(V,false);
        vector<bool> inRecurssion(V,false);
        vector<int> store(V,1);
        for(int i=0;i<V;i++){
            if(visited[i]==false){
                dfs(edges,i,visited,inRecurssion,store);
            }
        }
        return ans;

    }
};
