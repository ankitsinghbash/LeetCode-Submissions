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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> store;
        if(root==NULL){
            return {};
        }
        else{
            int level=-1;
            queue<TreeNode*> qu;
            qu.push(root);
            while(!qu.empty()){
                int size = qu.size();
                vector<int> sm;
                while(size--){
                   TreeNode *node = qu.front();
                   qu.pop();
                   sm.push_back(node->val);
                   if(node->left!=NULL){
                       qu.push(node->left);
                   }
                   if(node->right!=NULL){
                       qu.push(node->right);
                   }
                }
                level++;
                if(level%2!=0){
                    reverse(sm.begin(),sm.end());
                }
                store.push_back(sm);
                sm.clear();
            }
        }
        return store;
 
    }
};
