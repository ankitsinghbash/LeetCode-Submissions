class Solution {
public:
    typedef long long ll;
    long long maximumImportance(int n, vector<vector<int>>& roads) {
         vector<int> outgoing_edges(n,0);
         for(int i=0;i<roads.size();i++){
              int u=roads[i][0];
              int v=roads[i][1];

              outgoing_edges[u]++;
              outgoing_edges[v]++;
         }


        vector<pair<int,int>> p;
        for(int i=0;i<n;i++){
            int value = outgoing_edges[i];
            p.push_back({value,i});
        }

        sort(p.begin(),p.end());
      
        unordered_map<int,int> mp;
        for(int i=0;i<p.size();i++){
            int value = p[i].second;
            mp[value] = i+1;
        }


        ll ans=0;
        for(int i=0;i<roads.size();i++){
            int u = roads[i][0];
            int v = roads[i][1];

            ans+=mp[u];
            ans+=mp[v];
        }
        return ans;
         


    }
};
