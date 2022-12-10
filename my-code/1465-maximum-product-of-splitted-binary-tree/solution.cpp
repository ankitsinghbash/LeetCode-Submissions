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
    
    int treesum(TreeNode *root,vector<int> &sumofall){
        if(root==nullptr){
            return 0;
        }

       int   leftsum  = treesum(root->left,sumofall);
       int   rightsum = treesum(root->right,sumofall);
       int   sum=leftsum+rightsum+root->val;
       sumofall.push_back(sum);
       return sum;
    }

    int maxProduct(TreeNode* root) {
       constexpr int kmod = 1e9+7;

       long  ans=0;
       vector<int> sumofall;
       const long totalsum = treesum(root,sumofall);

       for(const  long  x : sumofall){
           
           ans=max(ans,x*(totalsum-x));
       }
       return ans%kmod;
    }
};
