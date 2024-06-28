class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
           vector<int> out_degree(n+1,0);
            vector<int> in_degree(n+1,0);


            for(int i=0;i<trust.size();i++){
                int  u = trust[i][0];
                int v = trust[i][1];

                 out_degree[u]++;
                 in_degree[v]++;
            }

           for(int i=1;i<n+1;i++){
              if(out_degree[i]==0 && in_degree[i]==n-1){
                return i;
              }
           }
           return -1;

    }
};
