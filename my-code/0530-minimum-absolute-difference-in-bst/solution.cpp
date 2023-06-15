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
 
   void solve(vector<int> &store,TreeNode *root){
       if(root==NULL) return;

       store.push_back(root->val);
       solve(store,root->left);
       solve(store,root->right);
   }


    int getMinimumDifference(TreeNode* root) {
        vector<int> store;
        solve(store,root);
        int mini = INT_MAX;
        sort(store.begin(),store.end());
        for(int i=1;i<store.size();i++){
            mini = min(mini,store[i]-store[i-1]);
        }
        return mini;

    }
};
