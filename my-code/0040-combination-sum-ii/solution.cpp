class Solution {
public:
   vector<vector<int>> ans;

   void helper(int i,vector<int> path,vector<int> candidates,int target)
   {
       if(target==0)
       {
           ans.push_back(path);
           return;
       }

       if(i>=candidates.size()||target<0)
       {
           return;
       }

        int prev  =-1;
        for(int k = i; k < candidates.size(); k++){
            int curr = candidates[k];
            if(curr == prev)
                continue;
            prev = curr;
            path.push_back(curr);                      //39 question have same approx with double calling:
            helper(k+1, path,candidates, target-curr);  //here increment in k because we does not required the value prev value:
            path.pop_back();           
        }


   }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        ans.clear();
        sort(candidates.begin(),candidates.end());
        int i=0;
        vector<int> path;
        helper(i,path,candidates,target);
        return ans;
    }
};


 
