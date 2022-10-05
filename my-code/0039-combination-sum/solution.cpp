class Solution {
public:
   vector<vector<int>> ans;

   void helper(int i,vector<int> path,vector<int> candidates,int target)
   {

      if(candidates.size()==i)
      {
          return;
      }
 
     if(target<0)
     {
         return;
     }

      if(target==0)
      {
          ans.push_back(path);
          return;
      }

      helper(i+1,path,candidates,target); //for traversal from,2,3,6,7:

     path.push_back(candidates[i]);
     helper(i,path,candidates,target-candidates[i]);  //from traversal according to i ,in first case i from 2 but in second case i from 3,in third case i from 6 and i last case i from 7;
     path.pop_back();

       
   }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
    int i=0;
    vector<int> path;
    helper(i,path,candidates,target);
    return ans;
    }
};
