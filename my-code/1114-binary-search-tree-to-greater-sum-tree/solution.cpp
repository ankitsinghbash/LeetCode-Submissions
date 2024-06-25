/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int  total_sum(TreeNode *value,TreeNode *root){

         if(root==NULL) return 0;


         int left = total_sum(value,root->left);
         int right = total_sum(value,root->right);
        
         int sum=0;
         if(root->val>=value->val){
             sum = root->val;
         }

         return sum+left+right;
    }

    TreeNode *solve(TreeNode* root,TreeNode* root1){

          if(root==NULL) return NULL;

          int sum = total_sum(root,root1);
          TreeNode *node  = new TreeNode(sum);
          node->left = solve(root->left,root1);
          node->right = solve(root->right,root1);

          return node;
    }

    TreeNode* bstToGst(TreeNode* root) {
        if(root==NULL) return NULL;
        return solve(root,root);
    }
};
