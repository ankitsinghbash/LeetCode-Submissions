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
   int sum=0;
   void solve(TreeNode *root,bool check){
    if(root==NULL){
        return;
    }
 
    if(check == false && root->left==NULL && root->right==NULL){
        sum+=root->val;
    }
      solve(root->left,false);
      solve(root->right,true);
   }
 


    int sumOfLeftLeaves(TreeNode* root) {
        bool val = true;
        solve(root,val);
        return sum;
    }
};
