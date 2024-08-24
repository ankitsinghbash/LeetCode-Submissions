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
    vector<int> largestValues(TreeNode* root) {
        //use level order traversal to find the maximum node value in each level of the tree:
        vector<int> ans;
        
        
         if(root==NULL){
             return {};
         }
        queue<TreeNode*> qu;
        qu.push(root);
        
        
        
        while(!qu.empty()){
             int size = qu.size();
             int maxx  = INT_MIN;
             while(size--){
                  TreeNode *node = qu.front();
                  qu.pop();
                  maxx = max(maxx,node->val);
                  if(node->left){
                      qu.push(node->left);
                  }
                  if(node->right){
                      qu.push(node->right);
                  }
             }
            ans.push_back(maxx);
        }
        
        return ans;
    }
};
