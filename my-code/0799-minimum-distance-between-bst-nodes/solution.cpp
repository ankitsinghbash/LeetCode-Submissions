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

   
   void dfs(TreeNode *root,vector<int> &ans){

      if(root==NULL) return;

      ans.push_back(root->val);
      dfs(root->left,ans);
      dfs(root->right,ans);

   }


    int minDiffInBST(TreeNode* root) {
        //property BST inorder always give an ascending data:
        vector<int> ans;
        dfs(root,ans);
        sort(ans.begin(),ans.end());
        int mini = INT_MAX;
        for(int i=1;i<ans.size();++i){
            mini = min(mini,abs(ans[i]-ans[i-1]));
        }
        return mini;
    }
};
