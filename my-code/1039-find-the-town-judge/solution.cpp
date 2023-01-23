class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indegree(n+1);   //a-->b means b is indegree and a is outdegree;
        vector<int> outdegree(n+1);
        for(vector<int> &x : trust){
            int u = x[0];
            int v  =  x[1];

            outdegree[u]++;
            indegree[v]++;
        }
  
        for(int i=1;i<n+1;i++){
            if(indegree[i]==n-1&&outdegree[i]==0){
                return i;
            }
        }
        return -1;

    }
};
