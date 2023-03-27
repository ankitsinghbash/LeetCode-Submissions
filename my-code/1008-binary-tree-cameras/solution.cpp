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
    int cnt=0;
  
    int solve(TreeNode *root){
        if(root==NULL){
            return 1;
        }
  
       int left = solve(root->left);
       int right = solve(root->right);

       if(left==-1 || right==-1){
           cnt++;
           return 0;
       }

       if(left==0 || right == 0 ){
           return 1;
       }
        
       if(left==1 && right==1){
           return -1;
       }
       return 1;  //we never come here:
    }


    int minCameraCover(TreeNode* root) {
       // solve(root);
 
        int ans = solve(root);
        if(ans==-1){
            cnt++;
        }
        return cnt;
    }
};
