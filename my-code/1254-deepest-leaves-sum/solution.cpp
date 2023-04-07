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
   
   int height(TreeNode *root){
       if(root==NULL){
           return 0;
       }
       return max(height(root->left),height(root->right))+1;
   }

   
   void solve(vector<int> &store,TreeNode *root,int height,int level){
       if(root==NULL) return;  
   
    
       if(level==height){
           store.push_back(root->val);
       }
   
       level++;
       solve(store,root->left,height,level);
       solve(store,root->right,height,level);
        
   }


    int deepestLeavesSum(TreeNode* root) {
        int total_height = height(root);
        vector<int> store;
        int level = 1;
        solve(store,root,total_height,level);
        int sum=0;
        for(auto &x : store){
            sum+=x;
        }
        return sum;
    }
};
