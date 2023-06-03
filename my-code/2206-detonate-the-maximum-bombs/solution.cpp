class Solution {
public:
    typedef long long ll;
   void dfs(int u,unordered_map<ll,vector<ll>> &adj,vector<bool> &vis){
       if(vis[u]==true) return;

       vis[u]=true;
       for(auto &v : adj[u]){
           if(vis[v]==false){
               dfs(v,adj,vis);
           }
       }
   }



    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        unordered_map<ll,vector<ll>> adj;
        for(int i=0;i<n;i++){
            ll x1 = bombs[i][0];
            ll y1 = bombs[i][1];
            ll r1 = bombs[i][2];

            for(int j=0;j<n;j++){
                if(i!=j){
                    ll x2 = bombs[j][0];
                    ll y2 = bombs[j][1];
                    ll r2 = bombs[j][2];
                    ll value  = (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
                    if(value<=r1*r1){
                    adj[i].push_back(j);
                    }
                }
            }
        }

      //applied dfs to each and every circle:
      int maxx = 0;
      for(int i=0;i<n;i++){
          int cnt=0;
          vector<bool> visited(n,false);
          dfs(i,adj,visited);

          for(int j=0;j<n;j++){
              if(visited[j]==true){
                  cnt++;
              }
          }

          for(int k=0;k<n;k++){
              visited[k]=false;  //fill vector again false;
          }
          maxx = max(maxx,cnt);
      }
      return maxx;
     

    }
   
};
