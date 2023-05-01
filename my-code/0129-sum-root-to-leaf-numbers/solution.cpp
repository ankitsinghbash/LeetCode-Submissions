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
  
   void solve(TreeNode *root,int &sum,string str){
       if(root==NULL){
           return;
       }
 
        
       str+=to_string(root->val);
       if(root->left==NULL && root->right==NULL){
            sum+=stoi(str);
            str.pop_back();
            return;
       }
 
      solve(root->left,sum,str);
      solve(root->right,sum,str);
      str.pop_back();
   }

 

 
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        solve(root,sum,"");
        return sum;
    }
};
