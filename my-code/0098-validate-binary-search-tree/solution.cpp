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
   bool solve(TreeNode *root,long long int maxx,long long int mini){
       if(root==NULL) return true;
    

       if(root->val<=mini || root->val>=maxx){
           return false;
       }

      bool left = solve(root->left,root->val,mini);
      bool right = solve(root->right,maxx,root->val);

      return left&&right;
   }




    bool isValidBST(TreeNode* root) {
        return solve(root,LONG_MAX,LONG_MIN);
    }
};
