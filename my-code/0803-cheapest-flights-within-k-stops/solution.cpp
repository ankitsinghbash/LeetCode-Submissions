class Solution {
public:
    //I am depend on k not at destination;
    //means find all the minimum cost path at k distance initial take dest as INT_MIN->and if in final state dest is not INT_MIN; means is reach the destination otherwise return -1;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<pair<int,int>>> adj;
        for(vector<int> &x : flights){
            int u = x[0];
            int v = x[1];
            int cost = x[2];

            adj[u].push_back({v,cost});
        }

        vector<int> dist(n,INT_MAX); //store the minimum cost of all the path from source;
        
        queue<pair<int,int>> qu;
        qu.push({src,0});
        dist[src]=0;

        int step=0;
        while(!qu.empty()&&step<=k){
           
             int N = qu.size();

             while(N--){
                  
               int u = qu.front().first;
               int vcost = qu.front().second;

               qu.pop();
               
               for(pair<int,int> &y : adj[u]){
                   int destination = y.first;
                   int cost = y.second;

                   if(dist[destination]>cost+vcost){  //means this cost is now less upate it:
                       dist[destination]=cost+vcost;

                      //if this cost is less again check less cost form here:
                      qu.push({destination,cost+vcost});

                   }
               }
               
             }
             step++; //at each level increase step;
           
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];

    }
};
