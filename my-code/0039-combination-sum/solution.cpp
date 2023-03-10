class Solution {
public:
   vector<vector<int>> ans;

   void helper(int idx,vector<int> path,vector<int> candidates,int target,int n)
   {

      if(idx>=n)  return;

 
     if(target<0)  return;
     

      if(target==0)
      {
          ans.push_back(path);
          return;
      }

    for(int i=idx;i<candidates.size();++i){
        path.push_back(candidates[i]);
         helper(i,path,candidates,target-candidates[i],n);  
         path.pop_back();
      }
       
   }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int> path;
    int n=candidates.size();
    helper(0,path,candidates,target,n);
    return ans;

    }
};
