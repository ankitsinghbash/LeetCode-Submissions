class Solution {
public:
   int leftheight(TreeNode *root){
       int height=0;
       while(root!=NULL){
           root=root->left;
           height++;
       }
       return height;
   }

   int rightheight(TreeNode *root){
     int height = 0;
     while(root!=NULL){
         root=root->right;
         height++;
     }
     return height;
   }

    int countNodes(TreeNode* root) {
        if(root==NULL){
            return 0;
        }

       int left_height = leftheight(root);
       int right_height = rightheight(root);

       if(left_height==right_height){
           return (1<<left_height)-1; //2power_leftheight
       }
  
       return countNodes(root->left)+countNodes(root->right)+1;     
    }
};
