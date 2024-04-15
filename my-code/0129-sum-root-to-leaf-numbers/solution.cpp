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
    int total=0;
    void solve(TreeNode *root,string str){
          if(root==NULL) return;
      
          str+=to_string(root->val);
 
          if(root->left==NULL && root->right==NULL){
            total+=stoi(str);
          }
            
          solve(root->left,str);
          solve(root->right,str);
          str.pop_back();


    }
    int sumNumbers(TreeNode* root) {
        string str;
        solve(root,str);
        return total;
    }
};
