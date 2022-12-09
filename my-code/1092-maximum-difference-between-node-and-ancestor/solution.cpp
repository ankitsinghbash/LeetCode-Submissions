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
   int ans;
    void check(TreeNode *root,int minTillNow,int maxTillNow)
    {
        if(!root)return;
        minTillNow=min(minTillNow,root->val);
        maxTillNow=max(maxTillNow,root->val);
        ans=max(ans,maxTillNow-minTillNow);
      //  realans=ans
        check(root->left,minTillNow,maxTillNow);
        check(root->right,minTillNow,maxTillNow);
    }

    int maxAncestorDiff(TreeNode* root) {
       if(!root) return 0;
       ans=0;
       check(root,INT_MAX,INT_MIN);
       return ans;
       
    }
};
