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

   //i required the height;
   int height(TreeNode *root,bool &ans){

      if(root==NULL){
          return 0;
      }

      int left = height(root->left,ans);
      int right = height(root->right,ans);
      if(abs(left-right)>1){
          ans=false;
      }
       
      return max(left,right)+1;

   }

    bool isBalanced(TreeNode* root) {
        bool ans = true;
        height(root,ans);
        return ans;
    }
};


// class Solution {
// public:
//     bool ans;
//     int checkBalance(TreeNode* root){
//         if(!root)
//             return 0;
//         if(!ans) // if Answer is already False then return it.
//             return 0;
//         int leftSubTree = checkBalance(root->left);
//         int rightSubTree = checkBalance(root->right);
//         if(abs(leftSubTree-rightSubTree) > 1){
//             ans = false;
//         }
//         return 1 + max(leftSubTree, rightSubTree);
//     }
//     bool isBalanced(TreeNode* root){
//         ans = true;
//         int temp = checkBalance(root);
//         return ans;
//     }
// };
