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
    int res=0;

    int solve(TreeNode *root){
      if(root==NULL) return 0;

     //  if(root->left==NULL && root->right==NULL) return 0; //not required condition:
     //root ki left,right koi bhi null ho mughe koi matlab nahi:

      int left = solve(root->left);
      int right =solve(root->right);

      int leftcheck=0;
      int rightcheck=0;
      if(root->left!=NULL && root->left->val==root->val){
          leftcheck=left+1;
      }
      if(root->right!=NULL && root->right->val==root->val){
          rightcheck=right+1;
      }

      res=max(res,leftcheck+rightcheck);
      return max(leftcheck,rightcheck);
    }

    int longestUnivaluePath(TreeNode* root) {
        solve(root);
        return res;
    }
};
