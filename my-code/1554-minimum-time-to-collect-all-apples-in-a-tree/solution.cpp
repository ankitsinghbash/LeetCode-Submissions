class Solution {
public:
    unordered_map<int,vector<int>> adj;

    int dfs(int curr,int parent,vector<bool> &hasapple){

       int time=0;
       for(auto &child : adj[curr]){
           if(child==parent){
               continue;
           }
           int timefromchild = dfs(child,curr,hasapple);
           if(timefromchild>0||hasapple[child]==true){
               time+=timefromchild+2;
           }
       }
      return time;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasapple) {
        for(auto &x : edges){
             int u = x[0];
             int v = x[1];

             adj[u].push_back(v);
             adj[v].push_back(u);
        }

        return dfs(0,-1,hasapple);
    }
};
