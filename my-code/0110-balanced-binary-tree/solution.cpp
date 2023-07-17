class Solution {
public:
  int solve(TreeNode *root,bool &start){

    if(root==NULL) return 0;

     
    int left = solve(root->left,start);
    int right = solve(root->right,start);

    if(abs(left-right)>1){
        start = false;
    }

    return 1+max(left,right);
      

  }



    bool isBalanced(TreeNode* root) {
      bool start = true;
      solve(root,start);
      return start; 
    }
};
