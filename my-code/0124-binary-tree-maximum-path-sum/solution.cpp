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
      if(root==NULL){
        return 0;
      }
  
      int left =  solve(root->left,ans);
      int right = solve(root->right,ans);


      int first = max(left,right)+root->val;
      int second = root->val;
      int third = left+right+root->val;
   
      ans = max({ans,first,second,third});

      return max(first,second);   //third isslyia nahi because root->ek path me hona chayia: agar third return means we break the condition of path:
   
    }




    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        solve(root,ans);
        return ans;
    }
};
