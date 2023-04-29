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
 
   int solve(TreeNode *root,int &ans){
     if(root==NULL) return 0;


     int l = solve(root->left,ans);
     int r = solve(root->right,ans);

     int only_root = root->val;
     int nicha_mil_gya = l+r+root->val;
     int koi_ek_acha = max(l,r)+root->val;

     ans = max({ans,only_root,nicha_mil_gya,koi_ek_acha});

     return max(only_root,koi_ek_acha);
     
   }

    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        solve(root,ans);
        return ans;
    }
};
