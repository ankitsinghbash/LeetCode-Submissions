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
    vector<int> first;
    vector<int> second;
    void solve(TreeNode *root,bool flag){
        if(root==NULL) return;  
        
        if(root->left==NULL && root->right==NULL && flag==true){
             first.push_back(root->val);
        }
        
        if(root->left==NULL && root->right==NULL && flag==false){
             second.push_back(root->val);
        }
        
        solve(root->left,flag);
        solve(root->right,flag);
    
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        solve(root1,true);
        solve(root2,false);
        return first==second ? true : false;
    }
};
