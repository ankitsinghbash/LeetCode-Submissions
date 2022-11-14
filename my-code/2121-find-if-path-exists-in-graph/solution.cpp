class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edge, int start, int last)  {
        vector<vector<int>> graph(n);
        for(int i=0;i<edge.size();i++)
        {
            graph[edge[i][0]].push_back(edge[i][1]);
            graph[edge[i][1]].push_back(edge[i][0]);
        }

       //BFS:
       vector<bool> visited(n,false);
       queue<int> qu;
       qu.push(start);
       visited[start]=true;
       while(!qu.empty())
       {
           int Top = qu.front();
           qu.pop();
           if(Top==last) return true;
           
           for(int i=0;i<graph[Top].size();i++)
           {
               if(visited[graph[Top][i]]==false)
               {
                   qu.push(graph[Top][i]);
                   visited[graph[Top][i]]=true;
               }
           }

       }
       return false;

    }
};
