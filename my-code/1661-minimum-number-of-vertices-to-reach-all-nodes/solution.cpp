class Solution {
public:
   void dfs(int u,vector<bool> &visited , unordered_map<int,vector<int>> &adj){
       if(visited[u]==true) return;

       visited[u]=true;
       for(auto &v : adj[u]){
           if(visited[v]==false){
               dfs(v,visited,adj);
           }
       }

   }




    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
       




        unordered_map<int,vector<int>> adj;
        for(int i=0;i<edges.size();i++){
             int u = edges[i][0];
             int v = edges[i][1];

             adj[u].push_back(v);
        }
  
        vector<int> indegree(n,0);
	    for(int u=0;u<n;u++){
	        for(auto &v : adj[u]){    
 	            indegree[v]++;
	        }
	    }
  
        vector<pair<int,int>> check;
        for(int i=0;i<n;i++){
            check.push_back({indegree[i],i});
        }
        sort(check.begin(),check.end());
        vector<int> store;
        for(auto x : check){
            store.push_back(x.second);
        }
  
       vector<bool> visited(n,false);

       vector<int> ans;
       for(int i=0;i<n;i++){ 
           int val = store[i];   //dfs ka order asa karo ki jiski outgoing max jo vo phale dfs kare:jissa minimum dfs node me all node cover ho jaay: ya indegree minimum ho jaay:
           auto it = adj.find(val);
           if(visited[val]==false && it!=adj.end()){   
               ans.push_back(val);
               dfs(val,visited,adj);
           }
       }
       return ans;

    }
};
