class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x){
        if(x==parent[x]){
            return x;
        }
        return parent[x]=find(parent[x]);
    }

    void Union(int x,int y){
        int x_parent = find(x);
        int y_parent = find(y);

         if(rank[x_parent]<rank[y_parent]){
           parent[x_parent]=y_parent;
        }
        else if(rank[x_parent]>rank[y_parent]){
             parent[y_parent] = x_parent;
        }
        else{
          parent[y_parent] = x_parent;
          rank[x_parent]++;
        } 
    }

    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        //Implement using DFS : Disjoint union set:
        int result=0;
        int n = vals.size();
        parent.resize(n);
        rank.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        unordered_map<int,vector<int>> adj;
    
        for(auto &vec : edges){
             int start = vec[0];
             int end = vec[1];

             adj[start].push_back(end);
             adj[end].push_back(start);
        }

        //taken value map for value_to_node:
        map<int,vector<int>> value_to_node;
        for(int i=0;i<n;i++){
            int val = vals[i];
            value_to_node[val].push_back(i);
        }
 
       //Now main logic to implementation of the question:
       //vector<int> store;
       vector<bool> is_active(n,false);
       for(auto it=value_to_node.begin();it!=value_to_node.end();it++){
               vector<int> node= it->second;
               for(auto &u : node){
                      for(auto &v : adj[u]){
                          if(is_active[v]){
                              Union(u,v);
                          }
                      }
                      is_active[u]=true;
               }

               vector<int> tumhare_parents;
               for(int i=0;i<node.size();i++){
                   int main_parent = find(node[i]);
                   tumhare_parents.push_back(main_parent);
               }

            //   unordered_map<int,int> mp1;
            //   for(int i=0;i<tumhare_parents.size();i++){
            //       mp1[tumhare_parents[i]]++;
            //   }

            //   for(auto it = mp1.begin();it!=mp1.end();it++){
            //       int val = it->second;
            //       int cnt = val*(val-1)/2;
            //       result += cnt;
            //   }
            sort(tumhare_parents.begin(),tumhare_parents.end());
            int j=0;
            while(j<tumhare_parents.size()){
                int cnt=0;
                int curr = tumhare_parents[j];
                while(j<tumhare_parents.size() && tumhare_parents[j]==curr){
                    j++;
                    cnt++;
                }
                result+=cnt*(cnt-1)/2;
            }
       }
       return result+n;
    }
};
