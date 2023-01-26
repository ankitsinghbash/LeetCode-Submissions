class Solution {
public:
     
    void dfs(vector<int> &edges,int node,vector<bool> &visited,vector<int> &dist){
        visited[node]=true;
        int v = edges[node];

        if(v!=-1 && !visited[v]){
            visited[v]=true;
            dist[v]=1+dist[node];
            dfs(edges,v,visited,dist);
        }

    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        //node 1 means 0
        //node 2 means 1;

        int n = edges.size();
        vector<int> dist1(n,INT_MAX); //INT_MAX because we required min value other wise put 0;
        vector<int> dist2(n,INT_MAX);

        vector<bool> visited1(n,false);
        vector<bool> visited2(n,false);

        dist1[node1]=0;
        dist2[node2]=0;

        dfs(edges,node1,visited1,dist1);
        dfs(edges,node2,visited2,dist2);
   
       

        //now take the min value of each i of vector dist1,dist2 and find value in edges and return it's index;
        int index = -1;
        int mini = INT_MAX;
        for(int i=0;i<n;i++){
           int maxD = max(dist1[i],dist2[i]);
           if(mini>maxD){
               mini = maxD;
               index = i;
           }
        }
        return index;
    }
};
