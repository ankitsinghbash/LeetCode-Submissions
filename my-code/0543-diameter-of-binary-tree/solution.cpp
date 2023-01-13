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

       int l  = dfs(root->left);
       int r = dfs(root->right);
       int koi_ek = max(l,r)+1;
       int nicha_ho_jaay = l+r+1;
 
       ans=max({ans,koi_ek,nicha_ho_jaay});
       return koi_ek;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        ans=INT_MIN;
        dfs(root);
        ans-=1;  // -1 in final ans because output index start form 0 to count the size of path on diameter:
        return ans;
    }
};
