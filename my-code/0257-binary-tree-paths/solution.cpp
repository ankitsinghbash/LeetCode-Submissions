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
    vector<string> ans;

    void helper(TreeNode * root,vector<string> &ans,string str){
        
        
        if(!root){
              return;
        }
         
        if(root->left==NULL && root->right==NULL)
        {
            str+=to_string(root->val);
            ans.push_back(str);
            str.pop_back();
            return;
        }
        
        str+=to_string(root->val)+"->";
        helper(root->left,ans,str);
        helper(root->right,ans,str);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        helper(root,ans,"");
        return ans;
    }
};
