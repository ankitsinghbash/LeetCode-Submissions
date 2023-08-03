class Solution {
public:
    vector<vector<int>> ans;
    void solve(int idx,int n,int k,vector<int> &sm){


      if(sm.size()==k){
          ans.push_back(sm);
          return;
      }

   
       for(int i=idx;i<=n;i++){
           sm.push_back(i);
           solve(i+1,n,k,sm);
           sm.pop_back();
       }
        


    }


    vector<vector<int>> combine(int n, int k) {
        vector<int> sm;
        solve(1,n,k,sm);
        return ans;
    }
};
