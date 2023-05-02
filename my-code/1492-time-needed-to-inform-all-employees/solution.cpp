class Solution {
public:
    int ans = 0;
    int maxx = 0;
   void dfs(int u,unordered_map<int,vector<int>> &adj,vector<int> &info){
        
    
    
     for(auto v : adj[u]){
         ans+=info[u];
         maxx=max(maxx,ans);
         dfs(v,adj,info);
         ans-=info[u];
     }
 
   }



    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime){
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<n;i++){
            int val = manager[i];
            if(val!=-1){
            adj[val].push_back(i);
            }
        }


        dfs(headID,adj,informTime);
        return maxx;
    } 
};
