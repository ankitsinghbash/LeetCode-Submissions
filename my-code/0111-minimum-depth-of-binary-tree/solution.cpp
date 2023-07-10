class Solution {
public:
   int solve(TreeNode *root){
     if(root==NULL){
         return INT_MAX;
     }

     if(root->left==NULL && root->right==NULL){
         return 1;
     }


      int left = solve(root->left);
      int right = solve(root->right);

      return 1+min(left,right);

   }


    int minDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        return solve(root);
    }
};
