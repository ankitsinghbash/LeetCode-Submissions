class Graph {
public:
    vector<vector<int>> list;  
    vector<vector<int>> WT;  
    Graph(int n, vector<vector<int>>& edges) {
            list.resize(n);
            WT.resize(n, vector<int>(n, -1));
            for (auto& edge : edges) {
              int start = edge[0];
              int go = edge[1];
              int cost = edge[2];
              list[start].push_back(go);
              WT[start][go] = cost;
        }
    }
    
    void addEdge(vector<int> edge) {
        int source = edge[0];
        int go = edge[1];
        int cost = edge[2];
        list[source].push_back(go);
        WT[source][go] = cost;
    }
    
    int shortestPath(int node1, int node2) {
        int n = list.size();
        vector<int> dist(n, -1);
        dist[node1] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p;
        p.push({0, node1});
        while (!p.empty()) {
            int curr = p.top().second;
            p.pop();
            for (auto neighbor : list[curr]) {
                int new_dist = dist[curr] + WT[curr][neighbor];
                if (dist[neighbor] == -1 || new_dist < dist[neighbor]) {
                    dist[neighbor] = new_dist;
                    p.push({new_dist, neighbor});
                }
            }
        }
        return dist[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
