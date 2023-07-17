class Solution {
public:
   void solve(TreeNode *root,int &k,int &val){
      if(root==NULL) return;
     
      solve(root->left,k,val);
      k--;
      if(k==0){
         val=root->val;
      }    
      solve(root->right,k,val);
   }

    int kthSmallest(TreeNode* root, int k) {
        int val = 0;
        solve(root,k,val);
        return val;
    }
};
