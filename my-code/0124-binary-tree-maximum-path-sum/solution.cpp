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
    int maxx;
    int pathoftree(TreeNode *root,int &maxval){
     if(root==NULL) return 0;

     int leftval = max(0,pathoftree(root->left,maxval));
     int rightval =max(0,pathoftree(root->right,maxval)); //right me store 35:

     maxval= max(maxval,leftval+rightval+root->val);

     return max(leftval,rightval)+root->val;
    }

    int maxPathSum(TreeNode* root) {
    maxx=INT_MIN;
    pathoftree(root,maxx);
    return maxx;
    }
};
