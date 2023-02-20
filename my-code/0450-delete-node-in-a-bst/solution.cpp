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
    //find the maxx in the bst we know maxx is on right side and mini on left side:
    int maxx(TreeNode *root){
        if(root->right!=NULL){
            return maxx(root->right);
        }
        else{
            return root->val;
        }
    }
 
    TreeNode* deleteNode(TreeNode* root, int key) {
       if (root == NULL) return NULL;

       if(key < root->val) {
               root->left = deleteNode(root->left,key);
               return root;
        }
       else if(key > root->val) {
               root->right = deleteNode(root->right,key);
               return root;
        }
       else
        {
           if (root->left != NULL && root->right != NULL) {
           int lmx = maxx(root->left);
           root->val = lmx;
           root->left = deleteNode(root->left, lmx);
           return root;
           }

           else if (root->left != NULL){
              return root->left;
           }

           else if(root->right != NULL){
              return root->right;
           }
          else{
            return NULL;
         }
       }
    return root;
    }
};
