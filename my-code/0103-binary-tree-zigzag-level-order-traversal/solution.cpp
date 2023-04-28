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
    vector<vector<int>> ans;
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
      if(root==NULL){
          vector<vector<int>> check;
          return check;
      }
  
      int level=0;
      queue<TreeNode*> qu;
      qu.push(root);
      while(!qu.empty()){
          int size = qu.size();
          vector<int> store;
          while(size--){
              TreeNode *node = qu.front();
              qu.pop();
              store.push_back(node->val);
              if(node->left!=NULL){
                  qu.push(node->left);
              }
              if(node->right!=NULL){
                  qu.push(node->right);
              }
          }
          level++;
          if(level%2==0){
             reverse(store.begin(),store.end());
          }
          ans.push_back(store);
      }
      return ans;

    }
};
