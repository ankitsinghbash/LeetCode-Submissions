class Solution {
public:
 
   bool cycle_dfs(int u,unordered_map<int,vector<int>> &adj,vector<bool> &visited,vector<bool> &inRecursion){
        if(visited[u]==true) return true;
        
        visited[u]=true;
        inRecursion[u]=true;
        for(auto &v : adj[u]){
            if(!visited[v] && cycle_dfs(v,adj,visited,inRecursion)){
                return true;
            }
            else if(visited[v]==true && inRecursion[v]==true){
                return true;
            }
        }
        //at each dfs make all inRecusion as false;
        inRecursion[u]=false;
        return false;
    }
  

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites){
        stack<int> st;
        unordered_map<int,vector<int>> adj;

        for(int i=0;i<prerequisites.size();i++){
            int u = prerequisites[i][0];
            int v =  prerequisites[i][1];
             
            adj[v].push_back(u);
        }
        
        vector<bool> visited(numCourses,false);
        vector<bool> inRecursion(numCourses,false);

        for(int i=0;i<numCourses;i++){
            if(!visited[i] && cycle_dfs(i,adj,visited,inRecursion)){ //!visited say dfs uspe mat karo jo visited hai:
                return false;
            }
            
        }
        return true;

    }
};
