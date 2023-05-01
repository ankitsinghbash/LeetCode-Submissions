class Solution {
public:

  int  solve(TreeNode *root,int &ans){
    if(root==NULL) return 0;

   
    int left = solve(root->left,ans);
    int right = solve(root->right,ans); 
   

    int only_one = max(left,right)+1;
    int all = left+right+1;

    ans = max({ans,only_one,all});
    
    return only_one;
  }





    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int ans = INT_MIN;
        solve(root,ans);
        return ans-1;

    }
};
