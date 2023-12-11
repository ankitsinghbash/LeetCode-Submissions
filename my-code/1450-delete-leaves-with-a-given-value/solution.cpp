
class Solution {
public:
   TreeNode *Inorder(TreeNode *root,int target){
       if(root==NULL){
           return NULL;
       }

       root->left = Inorder(root->left,target);
       root->right = Inorder(root->right,target);
       if(root->left==NULL && root->right==NULL && root->val==target){
           root=nullptr;
       }

       return root;


   }


    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return Inorder(root,target);
    }
};
