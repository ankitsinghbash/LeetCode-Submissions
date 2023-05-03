class Solution {
public:
    TreeNode *solve(int &prestart,int instart,int inend,vector<int> &preorder,vector<int> &inorder){
      if(instart>inend || prestart>=preorder.size()){
          return NULL;
      }

       TreeNode *node = new TreeNode(preorder[prestart]);
       prestart++;
       int i;
       for(i=instart;i<=inend;i++){
           if(inorder[i]==node->val){
               break;
           }
       }


       node->left = solve(prestart,instart,i-1,preorder,inorder);
       node->right = solve(prestart,i+1,inend,preorder,inorder);
       return node;

    }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int prestart = 0;
        int instart = 0;
        int inend = inorder.size()-1;
        return solve(prestart,instart,inend,preorder,inorder);
    }
};
