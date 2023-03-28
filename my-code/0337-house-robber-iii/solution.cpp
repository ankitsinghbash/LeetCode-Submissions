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

   vector<int> solve(TreeNode *root){
        if(root==NULL){
            vector<int> arr(2,0);
         return arr;
        }


         vector<int> leftcall = solve(root->left);
         vector<int> rightcall = solve(root->right);

         vector<int> option(2,0);

        option[0] = root->val+ leftcall[1] + rightcall[1];
        option[1] = max(leftcall[0],leftcall[1])+max(rightcall[0],rightcall[1]); 
        
        return option;
   }



    int rob(TreeNode* root) {
        vector<int> ans= solve(root);
        return max(ans[0],ans[1]);
    }
};
