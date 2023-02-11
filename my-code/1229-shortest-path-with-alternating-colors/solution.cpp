class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int> ans(n, -1);
        vector<vector<vector<int>>> graph(2, vector<vector<int>>(n));
        for(vector<int>& rE: redEdges)
            graph[0][rE[0]].push_back(rE[1]);
        for(vector<int>& bE: blueEdges)
            graph[1][bE[0]].push_back(bE[1]);
        queue<pair<int, bool>> q;
        q.push({0, true});
        q.push({0, false});
        int path = 0, size , u;
        bool col;
        vector<vector<bool>> visited(2, vector<bool>(n, false));
        while(!q.empty()) {
            size = q.size();
            while(size--) {
                u = q.front().first;
                col = q.front().second;
                q.pop();
                if(visited[col][u])
                    continue;
                visited[col][u] = true;
                if(ans[u] == -1)
                    ans[u] = path;
                for(int v: graph[!col][u])
                    if(!visited[!col][v])
                        q.push({v, !col});
            }
            path++;
        }
        return ans;
    }
};
