class Solution {
public:
    int largestPathValue(string color, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;

        int N = color.size();   //not use edges.size():
        vector<int> indegree(N,0);

        for(int i=0;i<edges.size();++i){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> qu;
        vector<vector<int>> t(N,vector<int>(26,0));  //Value vs / color box:
        
        //push indegree 0 in queue:
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                qu.push(i);
                t[i][color[i]-'a']=1;  //store t[i][color]:  //store 1 because it max length of color is 1:
            }
        }

        int answer = 0;
        int counter_Node = 0;
        while(!qu.empty()){
            int u = qu.front();
            qu.pop();
            counter_Node++;
   
            answer = max(answer,t[u][color[u]-'a']);

            for(int &v : adj[u]){
                  // go to every color , and color may be possible as 26 type:
                  for(int i=0;i<26;i++){
                      t[v][i]=max(t[v][i],t[u][i]+(color[v]-'a'==i));  //if color same hua to +1 other wise plus 0;
                  }

                   indegree[v]--;
                   if(indegree[v]==0){
                       qu.push(v);
                   }

            }
            
        }

        if(counter_Node<N){
            return -1;
        }
        return answer;

    }
};
