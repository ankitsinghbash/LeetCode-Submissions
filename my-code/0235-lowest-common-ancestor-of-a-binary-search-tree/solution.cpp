/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
  TreeNode *solve(TreeNode *root,TreeNode *p,TreeNode *q){
    
    //dry run for 3->1
    //note that order of if and else if fix:otherwise dry on 3,1 test case: 
     if(p->val<root->val && q->val < root->val){
         return solve(root->left,p,q);
     }
     else if(p->val>root->val && q->val>root->val){
         return solve(root->right,p,q);
     }
     else{
         return root;
     }

  }




    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root,p,q);
    }
};
