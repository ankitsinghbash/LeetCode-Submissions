class Solution {
public:
    int maxx=0;
    int solve(TreeNode *root){
      
        if(root==NULL) return 0;


        int left = solve(root->left);
        int right = solve(root->right);

        int current = left+right+1;
        

        maxx = max({maxx,current});
        return max(left,right)+1;
    

    }

    int diameterOfBinaryTree(TreeNode* root) {
        solve(root);
        return maxx-1;
    }
};
