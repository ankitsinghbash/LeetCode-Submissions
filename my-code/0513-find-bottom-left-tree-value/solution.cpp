class Solution {
public:
    int maxxheight(TreeNode *root){
        if(root==NULL) return 0;


         int left = maxxheight(root->left);
         int right = maxxheight(root->right);
        
         return max(left,right)+1;
    }

    int ans=0;
    int i=0;
    void solve(TreeNode *root,int height,int cnt){
             if(root==NULL) return;


             if(height==cnt && i==0){
                   ans = root->val;
                   i++;
             }


             solve(root->left,height,cnt+1);
             solve(root->right,height,cnt+1);

    }

    int findBottomLeftValue(TreeNode* root) {
        int height = maxxheight(root);
        int cnt=1;
        solve(root,height,cnt);
        return ans;
    }
};
