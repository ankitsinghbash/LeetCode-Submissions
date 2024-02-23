class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
         //simple bfs:
         vector<int> dist(n,INT_MAX);

         unordered_map<int,vector<pair<int,int>>> mp;

         for(int i=0;i<flights.size();i++){
             int start = flights[i][0];
             int end   = flights[i][1];
             int cost  = flights[i][2];

             mp[start].push_back({end,cost});
         }


         queue<pair<int,int>> qu;
         int cnt=0;   //this denote the number of stop in a flight:
         qu.push({src,0});
         int currcost=0;

         while(!qu.empty() && cnt<=k){
                int size = qu.size();
                while(size--){
                   
                    auto data = qu.front();
                    qu.pop();
                    int v = data.first;
                    int cost = data.second;
         
                    for(auto &x : mp[v]){
                           int destination = x.first;
                           int cost_second = x.second;

                           if(dist[destination]>cost+cost_second){
                               dist[destination] = cost+cost_second;
                               qu.push({destination,cost+cost_second});
                           }

                    }


                }
                cnt++;
         }

         if(dist[dst]==INT_MAX){
             return -1;
         }
         return dist[dst];

    }
};
