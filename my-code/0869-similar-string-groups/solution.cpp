class Solution {
public:

   void dfs(unordered_map<int,vector<int>> &adj,int u,vector<bool> &visited){

         if(visited[u]==true){
             return;
         }  
        
        visited[u]=true;
         for(auto v : adj[u]){
             if(visited[v]==false){
                 dfs(adj,v,visited);
                 visited[v]=true;
             }
         }

   }

    bool isSimilar(string &str1,string &str2){
        int diff = 0;
        for(int i=0;i<str1.size();i++){
            if(str1[i]!=str2[i]){
                diff++;
            }
        }
        return diff==0 || diff == 2;
    }


    int numSimilarGroups(vector<string>& strs) {
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<strs.size();i++){
            for(int j=i+1;j<strs.size();j++){
                if(isSimilar(strs[i],strs[j])){
                adj[i].push_back(j);
                adj[j].push_back(i);
                }
            }
        }

        int n = strs.size();
        int cnt=0;
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            if(visited[i]==false){
                dfs(adj,i,visited);
                cnt++;
            }
        }
       return cnt;
    }
};
