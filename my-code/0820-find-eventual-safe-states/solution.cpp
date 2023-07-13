class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        unordered_map<int,vector<int>> adj;
        int V = graph.size();
        vector<int> indegree(V,0);
        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[i].size();j++){
                int data = graph[i][j];
                adj[data].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> qu;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                qu.push(i);
            }
        }

      vector<int> store;
       while(!qu.empty()){
            int size = qu.size();
            while(size--){
                int node = qu.front();
                qu.pop();
                store.push_back(node);
                for(auto &v : adj[node]){
                    indegree[v]--;
                    if(indegree[v]==0){
                        qu.push(v);
                    }
                }
            }
       }
       sort(store.begin(),store.end());
       return store;    
  }
};
