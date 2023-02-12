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
    int maxLevelSum(TreeNode* root) {
        //i use bfs and store the level int maxx and return it;
        queue<TreeNode*> qu;
        qu.push(root);
        int level=0;
        int maxx = INT_MIN;
        int ans=level;
       // maxx=max(maxx,root->val);
        while(!qu.empty()){
         //  level++;
           int size = qu.size();
           int sum=0;
           while(size--){
               TreeNode *node = qu.front();
               qu.pop();
               sum+=node->val;
               if(node->left!=NULL){
                   qu.push(node->left);
               }
               if(node->right!=NULL){
                   qu.push(node->right);
               }
           }
           level++;
           if(sum>maxx){
               maxx=sum;
               ans=level;
           }
 
        }
        return ans;
    }
};
