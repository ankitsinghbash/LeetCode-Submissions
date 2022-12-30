class Solution {
public:
   vector<vector<int>> result;
   vector<int> temp;
 
   void dfs(vector<vector<int>> &graph,int curr)
   {
       
         temp.push_back(curr);

         if(curr==graph.size()-1){
            result.push_back(temp);
         }       
         

        for(int i=0;i<graph[curr].size();i++)
        {
            dfs(graph,graph[curr][i]);
        }
        temp.pop_back();


   }
   
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int curr=0;
        dfs(graph,curr);
        return result;
    }
};
