class Solution {
public:
    bool dfs(int u,vector<bool> &visited,vector<bool> &inRecurssion,unordered_map<int,vector<int>> &adj){

 
   
              visited[u]=true;
              inRecurssion[u]=true;
              for(auto &v : adj[u]){
                 if(visited[v]==true && inRecurssion[v]==true){
                     return true;
                 }
                 if(visited[v]==false){
                    if(dfs(v,visited,inRecurssion,adj)==true){
                        return true;
                    }
                 }

              }


              inRecurssion[u]=false;
              return false;
    }



    bool canFinish(int numCourses, vector<vector<int>>& box) {
        //also use cyclic detection in directed graph:
        unordered_map<int,vector<int>> adj;
        int V = numCourses;
        for(int i=0;i<box.size();i++){
            int a = box[i][0];
            int b = box[i][1];
            adj[b].push_back(a);
        }
          


        vector<bool> inRecurssion(V,false);
        vector<bool> visited(V,false);


         for(int i=0;i<V;i++){
            if(visited[i]==false && dfs(i,visited,inRecurssion,adj)){
                return false;
            }
         }


         return true;




    }
};
