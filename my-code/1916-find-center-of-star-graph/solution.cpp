class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        //the node that are comman in all is the center of the graph:
        //that degree equal to edges.size()-1 is also a center of graph
        int n = edges.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            int u = edges[i][0];
            int v = edges[i][1];

            mp[u]++;
            mp[v]++;
        }
       

        int size = edges.size();
        for(auto it = mp.begin();it!=mp.end();it++){
            if(it->second==size){
                return it->first;
            }
        }
        return -1;

    }
};
