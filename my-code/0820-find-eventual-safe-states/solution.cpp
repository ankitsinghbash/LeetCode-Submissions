class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        unordered_map<int,vector<int>> adj;
       
        int V =graph.size();
       
        vector<int> indegree(V,0);
        for(int i=0;i<V;i++){
            for(auto &x : graph[i]){
                adj[x].push_back(i);  //reverse the edge:   x-->i
                indegree[i]++;     
                //adj[i].push_back(x);
            }
        }

        queue<int> qu;  //put all indegree in queue:
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                qu.push(i);
            }
        }

        vector<int> ans;
        while(!qu.empty()){
            int node = qu.front();
            qu.pop();
            ans.push_back(node);
            for(auto &x : adj[node]){
                indegree[x]--;
                if(indegree[x]==0){
                    qu.push(x);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;


      


    }
};
