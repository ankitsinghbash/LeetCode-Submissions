class Solution {
public:
   
   bool check(vector<int> &myvec){
       for(int i=1;i<myvec.size();i++){
           if(myvec[i-1]>myvec[i]){
               return false;
           }
       }
       return true;
   }



   set<vector<int>> sv;
   void solve(int idx,vector<int> &nums,vector<int> &path,int n){

      if(idx==n){
          if(path.size()>=2&&check(path)){
                sv.insert(path);
          }
          return;
      }

  
       path.push_back(nums[idx]);
       solve(idx+1,nums,path,n);
       path.pop_back();
       solve(idx+1,nums,path,n);

   }
 

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n=nums.size();

        
        vector<int> path;
        solve(0,nums,path,n);
        
        vector<vector<int>> ans;
        for(auto x : sv){
            ans.push_back(x);
        }
        return ans;
    }
};
