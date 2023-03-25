class Solution {
public:

  void dfs(int u,unordered_map<int,vector<int>> &adj,vector<bool> &visited,vector<bool> &inRecursion,stack<int> &st,bool &hascycle){
      if(visited[u]==true) return;

      visited[u]=true;
      inRecursion[u]=true;
      for(auto &v : adj[u]){
          //check condition of cycle in the directed graph:
          if(inRecursion[v]==true){ //visited[v]==true && inRecursion[v]==true
              hascycle=true;
              return;
          }
          if(visited[v]==false){
              dfs(v,adj,visited,inRecursion,st,hascycle);
          }
      }
      st.push(u);
      inRecursion[u] = false;
  }


  
    vector<int> findOrder(int V, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adj;
        for(auto &vec : prerequisites){
            int u = vec[0];
            int v = vec[1];

            adj[v].push_back(u);
        }
  
        vector<bool> visited(V,false);
        vector<bool> inRecursion(V,false);
        
       bool hascycle=false;
        stack<int> st;
        for(int i=0;i<V;i++){
            if(visited[i]==false){
                dfs(i,adj,visited,inRecursion,st,hascycle);
            }
        }

        if(hascycle==true){
            return {};
        }

        vector<int> ans;
        while(!st.empty()){
            cout<<st.top()<<" "<<endl;
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
        

    }
};
