class Solution {
public:
    
    vector<vector<int>>result;
    vector<int> temp;
void dfs(vector<vector<int>>& graph,int curr)
{
    temp.push_back(curr);
    if(curr== graph.size()-1)
    {
        result.push_back(temp);
    }
    for(int j=0;j<graph[curr].size();j++)
    {
        dfs(graph,graph[curr][j]);
    }
    temp.pop_back();
}  

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    result.clear();
    temp.clear();
    dfs(graph,0);
    return result;
    }
};





