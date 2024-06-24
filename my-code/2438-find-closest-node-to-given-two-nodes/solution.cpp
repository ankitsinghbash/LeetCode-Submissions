class Solution {
public:
    void dfs(unordered_map<int,vector<int>> &mp,int current,vector<int> &dist,vector<bool> &visited){
           if(visited[current]==true) return;


           visited[current]=true;
           for(auto &u : mp[current]){
               if(u!=-1 && visited[u]==false){
                     dist[u] = dist[current]+1;
                     dfs(mp,u,dist,visited);
               }
           }

    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        unordered_map<int,vector<int>> mp;
        int n = edges.size();
        for(int i=0;i<n;i++){
            int v = edges[i];
            mp[i].push_back(v);
        }


        vector<int> dist1(n,-1);
        vector<int> dist2(n,-1);
        vector<bool> visited1(n,false);
        vector<bool> visited2(n,false);
        dist1[node1]=0;
        dist2[node2]=0;
       
        dfs(mp,node1,dist1,visited1);
        dfs(mp,node2,dist2,visited2);


      
        
        int mini  = INT_MAX;
        int ans=-1;
        for(int i=0;i<n;i++){
            if(dist1[i]==-1 || dist2[i]==-1){
                continue;
            }
            int value = max(dist1[i],dist2[i]);
            if(value<mini){
                mini = value;
                ans = i;
            }

        }
        return ans;

         
    }
};
