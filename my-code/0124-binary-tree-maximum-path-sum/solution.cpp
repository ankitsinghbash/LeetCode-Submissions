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
    int ans;
    int dfs(TreeNode *root){
       if(root==NULL){
           return 0;
       }
    
      int l = dfs(root->left);
      int r = dfs(root->right);
      
      int koi_ek_acha = max(l,r)+root->val;
      int only_root_acha = root->val;
      int nicha_hi_mil_gya = l+r+root->val;
    
      ans = max({ans,koi_ek_acha,only_root_acha,nicha_hi_mil_gya});

       return max(koi_ek_acha,only_root_acha);
    }

    int maxPathSum(TreeNode* root) {
        ans=INT_MIN;
        dfs(root);
        return ans;
    }
};
