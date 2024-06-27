class Solution {
public:
    int ans = -1;
    void dfs(int u,vector<bool> &visited,vector<bool> &inRecurssion,vector<int> &cnt,vector<int> &edges){

         
         visited[u] = true;
         inRecurssion[u]=true;
         int v = edges[u];
         if(v!=-1 && visited[v]==false){
            cnt[v]=cnt[u]+1;
            dfs(v,visited,inRecurssion,cnt,edges);
         }
         else if(v!=-1 && visited[v]==true && inRecurssion[v]==true){
               ans = max(ans,cnt[u]-cnt[v]+1);
         }

         inRecurssion[u]=false;


    }

    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool> visited(n,false);
        vector<bool> inRecurssion(n,false);
        vector<int> cnt(n,1);
        for(int i=0;i<n;i++){
            if(visited[i]==false){
                dfs(i,visited,inRecurssion,cnt,edges);
            }
        }
        return ans;
    }
};
