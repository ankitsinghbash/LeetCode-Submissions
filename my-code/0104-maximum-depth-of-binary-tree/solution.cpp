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
//method 1 by bfs traversal level order:
    int maxDepth(TreeNode* root) {
       if(root==NULL){
           return 0;
       }

        //by bfs:
        queue<TreeNode*> qu;
        qu.push(root);
        int level=0;
        while(!qu.empty()){
            int size = qu.size();
            while(size--){
                TreeNode *node = qu.front();
                qu.pop();
                if(node->left!=NULL){
                    qu.push(node->left);
                }
                if(node->right!=NULL){
                    qu.push(node->right);
                }
            }
            level++;
        }
        return level;
    }
};

// class Solution {
// public:
   
//    int solve(TreeNode *root){
//         if(root==NULL) return 0;

//         int left = solve(root->left);
//         int right = solve(root->right);
 
//         return max(left,right)+1;

//    }
  

//     int maxDepth(TreeNode* root) {
//        return solve(root); 
//     }
// };
