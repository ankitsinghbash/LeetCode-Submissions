class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        unordered_map<int,vector<pair<int,double>>> adj;

        vector<double> dist(n,0.0);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double pro = succProb[i];

            adj[u].push_back({v,pro});
            adj[v].push_back({u,pro});
        }


        priority_queue<pair<double,int>> pq; 
        dist[start]=1.0;  
        pq.push({1.0,start});
        while(!pq.empty()){
          double curr_pro = pq.top().first;
          int node = pq.top().second;

          pq.pop();

          for(auto x : adj[node]){
               int new_node = x.first;
               double new_pro=x.second;

               if(dist[new_node]<curr_pro*new_pro){
                   dist[new_node] = curr_pro*new_pro;
                   pq.push({dist[new_node],new_node});
               }   
          }
        }
        return dist[end];
    }
};
