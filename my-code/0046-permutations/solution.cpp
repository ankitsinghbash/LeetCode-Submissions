class Solution {
public:
  
  vector<vector<int>> realans;

  void solve(int i,int n,vector<int> nums){

     if(i==n){
         realans.push_back(nums);
         return;
     }


      for(int k=i;k<n;k++){
          swap(nums[i],nums[k]);
          solve(i+1,n,nums);  //remember call are at i not a generally k+1;
      }

  }


    vector<vector<int>> permute(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        solve(i,n,nums);
        sort(realans.begin(),realans.end());
        return realans;
    }
};
