class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        //using bfs:
        // 0---1,2;
        // 1---0,2,3;
        // 2---0,1;

        // 3---1;

        if(source==destination) return true;

        unordered_map<int,vector<int>> mp;
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];

            mp[u].push_back(v);
            mp[v].push_back(u);

        }

        queue<int> qu;
        vector<int> visited(n,false);
        visited[source]=true;
        qu.push(source);

        while(!qu.empty()){
            int size = qu.size();
            while(size--){
                int u = qu.front();
                qu.pop();
                for(auto &v : mp[u]){
                    if(visited[v]==false){
                       
                        qu.push(v);
                        visited[v]=true;
                         if(v==destination) return true;
                    }
                }
            }
        }
        return false;

    }
};
