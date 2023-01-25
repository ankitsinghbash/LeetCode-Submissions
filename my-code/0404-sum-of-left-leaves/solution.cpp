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
    int ans=0;
    void dfs(TreeNode *root,bool val){

      if(root==NULL){
          return;
      }

      if(val==true && root->left==NULL && root->right == NULL){
          ans+=root->val;
      }

   
       dfs(root->left,true);
       dfs(root->right,false);

    }
    int sumOfLeftLeaves(TreeNode* root) {
        bool val = false;
        dfs(root,val);
        return ans;
    }
};
