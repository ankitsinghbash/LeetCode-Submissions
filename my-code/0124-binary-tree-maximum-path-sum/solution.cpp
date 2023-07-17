class Solution {
public:
  int solve(TreeNode *root,int &maxx){
     if(root==NULL) return 0;

    int left = solve(root->left,maxx);
    int right = solve(root->right,maxx);

    int first = root->val+max(left,right);
    int second = root->val;
    int third = root->val+left+right;
    maxx = max({first,second,third,maxx});
    return max(first,second);
  }



    int maxPathSum(TreeNode* root) {
       int maxx = INT_MIN;
       solve(root,maxx);
       return maxx; 
    }
};
