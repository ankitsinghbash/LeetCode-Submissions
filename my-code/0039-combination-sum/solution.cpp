class Solution {
public:
    vector<vector<int>> box;
    void solve(int i,vector<int> &candidates,int target,vector<int> &sm){
          if(i>=candidates.size()) return;

          if(target<0) return;

           
          if(target==0){
            box.push_back(sm);
            return;
          }
           
          sm.push_back(candidates[i]);
          solve(i,candidates,target-candidates[i],sm);
          sm.pop_back();
          solve(i+1,candidates,target,sm);
          

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> sm;
        solve(0,candidates,target,sm);
        return box;
    }
};
