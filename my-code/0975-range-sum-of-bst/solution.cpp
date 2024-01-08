class Solution {
public:
    int solve(TreeNode *root,int low,int high){
        if(root==NULL) return 0;

        int sum=0;
       if(root->val>=low && root->val<=high){
           sum+=root->val;
       }

       if(root->val<high){
           sum+=solve(root->right,low,high);
       }

       if(root->val>low){
           sum+=solve(root->left,low,high);
       }

       return sum;

      


    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        return solve(root,low,high);
    }
};
