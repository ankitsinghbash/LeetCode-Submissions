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
 
   void solve(TreeNode *root,int target,vector<vector<int>> &ans,vector<int> sm){

    if(root==NULL)return;

    target=target-root->val;
    sm.push_back(root->val);

    if(target==0 && root->left==NULL && root->right==NULL){
        ans.push_back(sm);
    }

    solve(root->left,target,ans,sm);
    solve(root->right,target,ans,sm);
    sm.pop_back();
    
   }




    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> sm;
        solve(root,targetSum,ans,sm);
        return ans;
    }
};
