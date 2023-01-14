class Solution {
public:

   char dfs(unordered_map<int,vector<int>> &adj,char curr_ch,vector<int> &visited){
   
      visited[curr_ch-'a']=1;  //make this visited;
      
      //let make fisrt as minimum:
      char mini = curr_ch;
      for(auto &child : adj[curr_ch]){
          if(visited[child-'a']==0){
              mini = min(mini,dfs(adj,child,visited));
          }
      }
      return mini;
   }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n=s1.size();
        int m=baseStr.size();
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<n;i++){
            char u = s1[i];
            char v = s2[i];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        string result;
        for(int i=0;i<m;i++){
            char ch = baseStr[i];
            vector<int> visited(26,0); //0 for unvisited:
            char minchar = dfs(adj,ch,visited);
            result.push_back(minchar);
        }
 
        return result;
    }
};
