class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        //using spanning tree algorithm:
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int n = points.size();
        vector<bool> visited(n,false);
        pq.push({0,0});
        int sum=0;
        int i=0;
        while(i<n){
               int wt = pq.top().first;
               int node = pq.top().second;
               pq.pop();
               if(visited[node]==true){
                   continue;
               }
                visited[node]=true;
                sum+=wt;
                i++;
                 int x1 = points[node][0];
                 int y1 = points[node][1];
                for(int j=0;j<n;j++){
                     if(visited[j]==false){
                     int x2 = points[j][0];
                     int y2 = points[j][1];
                     int val = abs(x1-x2)+abs(y1-y2);
                           pq.push({val,j});
                     }
                   }
               }
               return sum;
        }
       // return sum;
    
};
