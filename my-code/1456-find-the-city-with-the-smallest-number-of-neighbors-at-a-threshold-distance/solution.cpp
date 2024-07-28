class Solution {
public:
    //how bellman forld using in undirect graph:
    //many it is use in direct graph and if graph is undirect then convert it to directed and then use:
    struct cmp{
        bool operator()(const pair<int,int> &a,const pair<int,int> &b){
                      if(a.second==b.second){
                            return a.first>b.first;
                      }
                      return a.second<b.second;
        }
    };

    vector<int> bellman(int u,vector<vector<int>> &edges,int n ){

         vector<int> dist(n,INT_MAX);
         dist[u]=0;
          
         for(int i=1;i<=n-1;i++){ 


         for(auto &x : edges){
             int u = x[0];
             int v = x[1];
             int w = x[2];

             if(dist[u]!=INT_MAX && dist[u]+w<dist[v]){
                dist[v] = dist[u]+w;
             }

             if(dist[v]!=INT_MAX && dist[v]+w<dist[u]){
                dist[u] = dist[v]+w;
             }
         }
          
         }
         //no need to check negative cycle because there is no negative weight present in question:
         return dist;

    }
    
   

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    
         vector<vector<int>> matrix;

         for(int i=0;i<n;i++){
               matrix.push_back(bellman(i,edges,n));
         }

          
         vector<pair<int,int>> vec; 
         for(int i=0;i<matrix.size();i++){
                int cnt=0;
                for(int j=0;j<matrix[0].size();j++){
                    if(matrix[i][j]<=distanceThreshold){
                              cnt++;
                    }
                }
                vec.push_back({i,cnt});
         } 



         sort(vec.begin(),vec.end(),cmp());
           
         int ans = vec[0].first;
         return ans;


    }
};  
