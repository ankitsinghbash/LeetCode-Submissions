class Solution {
public:
   int result = -1;
   void dfs(int u,vector<int> &edges,vector<bool> &visited,vector<bool> &inRecursion,vector<int> &cnt){
   
      visited[u]=true;
      inRecursion[u]=true;
      int v = edges[u];
      if(v!=-1 && visited[v]==false){   //when no cycle:
          cnt[v]=cnt[u]+1;
          dfs(v,edges,visited,inRecursion,cnt);
      }
      else if(v!=-1 && inRecursion[v]==true){
          result = max(result,cnt[u]-cnt[v]+1);
      }

      inRecursion[u]=false;
   }



    
    int longestCycle(vector<int>& edges){
      
      int V = edges.size();
      vector<bool> visited(V,false);
      vector<bool> inRecursion(V,false);
      vector<int> cnt(V,1);

      for(int i=0;i<edges.size();i++){
          if(visited[i]==false){
              dfs(i,edges,visited,inRecursion,cnt);
          }
      }

        return result;
    }
};
