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

   void dfs(TreeNode *root,int target,vector<vector<int>> &real,vector<int> ans){
        
        if(root==NULL) return;
    
        if(root->left==NULL && root->right==NULL){
            ans.push_back(root->val);
            int total=0;
            for(auto &x : ans){
                total+=x;
            }
            if(total==target){
             real.push_back(ans);
            }
            ans.pop_back();
            return;
        }
     
        ans.push_back(root->val);
        dfs(root->left,target,real,ans);
        dfs(root->right,target,real,ans);
 

   }
   

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> real;
        vector<int> ans;
        dfs(root,targetSum,real,ans);
        return real;
    }
};
