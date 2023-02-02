class Solution {
public:
  void dfs(int u,vector<bool> &visited,unordered_map<int,vector<int>> &adjlist){
       
       if(visited[u]==true) return;
       
       visited[u]=true;
       for(auto &x : adjlist[u]){
           if(!visited[x]){
               dfs(x,visited,adjlist);
           }
       }
       
       
   }


    int findCircleNum(vector<vector<int>>& adj) {
         unordered_map<int,vector<int>> adjlist;
        for(int i=0;i<adj.size();i++)
        {
            for(int j=0;j<adj[0].size();j++)
            {
                if(i!=j && adj[i][j]==1)
                {
                    adjlist[i].push_back(j);
                    
                }
            }
        }
        
        vector<bool> visited(adj.size(),false);
        int counter=0;
        for(int i=0;i<adj.size();i++){
            if(!visited[i]){
            counter++;
            dfs(i,visited,adjlist);
            }
        }
        return counter;
    }
};
