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
   TreeNode *solve(int inStart,int inEnd,int pStart,int pEnd,vector<int> inorder,vector<int> postorder){
       if(pStart>pEnd || inStart>inEnd){
           return NULL;
       }


       TreeNode *root = new TreeNode(postorder[pEnd]);

       int i=inStart;
       for(;i<=inEnd;i++){
           if(root->val==inorder[i]){
               break;
           }
       }
   
       int left_ = i-inStart;
       int right_ = inEnd-i;
       
       root->left = solve(inStart,i-1,pStart,pStart+left_ -1,inorder,postorder);
       root->right = solve(i+1,inEnd,pEnd-right_,pEnd - 1,inorder,postorder);

       return root;

   }
   



    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int inStart = 0;
        int inEnd = inorder.size()-1;
        int pStart = 0;
        int pEnd = postorder.size()-1;
        return solve(inStart,inEnd,pStart,pEnd,inorder,postorder);
    }
};
