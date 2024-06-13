class Solution {
public:
    int ans = 0;
    void maxxLength(TreeNode *root,bool flag,int cnt){
       if(root==NULL){
           ans = max(ans,cnt);
           return;
       }

       if(flag==true){
            maxxLength(root->left,false,cnt+1);
       }
       else{
            maxxLength(root->right,true,cnt+1);
       }

    }


    void solve(TreeNode *root){
       if(root==NULL) return;

        maxxLength(root,true,0);
       maxxLength(root,false,0);
       
       solve(root->left);
       solve(root->right);

      


    }

    int longestZigZag(TreeNode* root) {
        //brute force first:
         solve(root);
         return ans-1;
    }
};
