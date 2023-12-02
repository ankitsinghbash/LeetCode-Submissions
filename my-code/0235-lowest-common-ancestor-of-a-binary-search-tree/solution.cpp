class Solution {
public:
    TreeNode *solve(TreeNode *root,TreeNode *p,TreeNode *q){
          //kabhi NULL tak gya hi nahi:
          if(p->val<root->val && q->val<root->val){
             return solve(root->left,p,q);
          }
          else if(p->val>root->val && q->val>root->val){
             return solve(root->right,p,q);
          }
         
        return root;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root,p,q);
    }
};
