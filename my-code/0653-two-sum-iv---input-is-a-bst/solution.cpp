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

   void Inorder(TreeNode *root,int k,vector<int> &ans){
       if(root==NULL) return;
      
       Inorder(root->left,k,ans);
       ans.push_back(root->val);
       Inorder(root->right,k,ans);
   }
 
    bool findTarget(TreeNode* root, int k) {
        vector<int> ans;
        Inorder(root,k,ans);

        //now the question is become two sum: where array is 
        unordered_map<int,int> mp;
        for(int i=0;i<ans.size();++i){
            mp[ans[i]]=i;
        }
     
        unordered_map<int,int> :: iterator it;
        for(int i=0;i<ans.size();i++){
            int val = k- ans[i];
            if(mp.find(val)!=mp.end() && mp[val]!=i){
                 return true;
            }
        }
       return false;

    }
};
