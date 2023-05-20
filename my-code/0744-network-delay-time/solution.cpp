class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int src) {
        //implementation of dijkstra algorithm:
        unordered_map<int,vector<pair<int,int>>> adj;
        for(auto &vec : times){
             int u = vec[0];
             int v = vec[1];
             int w = vec[2];

             adj[u].push_back({v,w});
        }
      
        vector<int> result(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        result[src] = 0;
        pq.push({0,src}); //distance vs src:

        while(!pq.empty()){
              int d = pq.top().first;
              int node = pq.top().second;
              pq.pop();

              for(auto &v : adj[node]){
                  int adjnode = v.first;
                  int adjdist = v.second;

                  if(d+adjdist<result[adjnode]){
                      result[adjnode] = d+adjdist;
                      pq.push({d+adjdist,adjnode});
                  }
              }
        }

      for(int i=1;i<n+1;i++){
          if(result[i]==INT_MAX) return -1;
      }
      int maxx = 0;
      for(int i=1;i<n+1;i++){
          maxx = max(maxx,result[i]);
      }
      return maxx;
  
    }
};
