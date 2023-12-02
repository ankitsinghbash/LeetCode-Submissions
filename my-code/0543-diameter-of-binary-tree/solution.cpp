class Solution {
public:
   int maxx=INT_MIN;
   int solve(TreeNode *root){
       if(root==NULL){
           return 0;
       }

       int left = solve(root->left);
       int right = solve(root->right);

       maxx = max(maxx,left+right+1);
       return max(left,right)+1;
   }

    int diameterOfBinaryTree(TreeNode* root) {
        solve(root);
        return maxx-1;
    }
};
