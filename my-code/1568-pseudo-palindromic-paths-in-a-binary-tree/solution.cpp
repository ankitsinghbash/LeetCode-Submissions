class Solution {
public:
   void solve(TreeNode *root,unordered_map<int,int> &mp,int &ans){
     if(root==NULL)  return;      

      mp[root->val]++;
      if(root->left==NULL && root->right==NULL){
          int cnt=0;
          for(auto it =mp.begin();it!=mp.end();it++){
              if(it->second%2!=0){
                  cnt++;
              }
          }
          if(cnt<=1){
              ans++;
          }
      }

      solve(root->left,mp,ans);
      solve(root->right,mp,ans);
      mp[root->val]--;
   }



    int pseudoPalindromicPaths (TreeNode* root) {
    
        int ans = 0;
        unordered_map<int,int> mp;
        solve(root,mp,ans);
        return ans;
    }
};
