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
  
   TreeNode *solve(int &preStart,int postStart,int postEnd,vector<int> preorder,vector<int> postorder){
     if(postStart>postEnd || preStart>=preorder.size()) return NULL;
    
      TreeNode *root = new TreeNode(preorder[preStart]);
      preStart++;

      if(postStart==postEnd){
          return root;
      }

      int i=postStart;
      for(;i<=postEnd;i++){
          if(postorder[i]==preorder[preStart]){
              break;
          }
      }
 
      int idx = i;
      root->left = solve(preStart,postStart,idx,preorder,postorder);
      root->right = solve(preStart,idx+1,postEnd-1,preorder,postorder);
      return root;
    

   }



    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int preStart = 0;
        int preEnd = preorder.size()-1;
        int postStart = 0;
        int postEnd = postorder.size()-1;
        return solve(preStart,postStart,postEnd,preorder,postorder);
    }
};
