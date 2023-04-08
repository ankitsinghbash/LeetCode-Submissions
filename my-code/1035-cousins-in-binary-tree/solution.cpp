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
   int h1,h2;
   int parent1,parent2;
   void find1(TreeNode *root,int x,int y,int level,int parent){
     if(root==NULL) return;
     
     if(root->val==x){
        h1=level;
        parent1=parent;
     }

     if(root->val==y){
         h2=level;
         parent2=parent;
     }

     level++;
     find1(root->left,x,y,level,root->val);
     find1(root->right,x,y,level,root->val);
   }
   
     
    bool isCousins(TreeNode* root, int x, int y) {
        find1(root,x,y,0,-1);
        if(h1==h2 && parent1!=parent2){
            return true;
        }
        return false;
    }
};
