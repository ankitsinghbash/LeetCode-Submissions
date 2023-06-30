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
   stack<TreeNode*> st;
   void solve(TreeNode *root){
       while(root!=NULL){
           st.push(root);
           root=root->left;
       }
   }

    vector<int> inorderTraversal(TreeNode* root) {
        //Inorder traversal using stack
    
        solve(root);
        vector<int> ans;
        while(!st.empty()){
          TreeNode *node= st.top();
          ans.push_back(node->val);
          st.pop();
          solve(node->right);
        }
        return ans;
    }
};
