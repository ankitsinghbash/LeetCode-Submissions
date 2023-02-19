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
  
   int count_node(TreeNode *root){
       if(root==NULL) return 0;

       return 1+count_node(root->left)+count_node(root->right);
   }


   bool check(TreeNode *root,int i,int total_node){
     
     if(root==NULL){
         return true;
     }

     if(i>=total_node){
         return false;
     }     

      return check(root->left,2*i+1,total_node)&&check(root->right,2*i+2,total_node);
     
   }

    bool isCompleteTree(TreeNode* root) {
         //using dfs:
         int node_size = count_node(root);
         int idx=0;
         return check(root,idx,node_size);
    }
};



//using Breath first search:
// class Solution {
// public:
//     bool isCompleteTree(TreeNode* root) {
//         //bfs:
//         bool past = false;
//         queue<TreeNode*> qu;
//         qu.push(root);
//         while(!qu.empty()){
//             int size = qu.size();
//             while(size--){
//                 TreeNode *node = qu.front();
//                 qu.pop();
//                 if(node==NULL){
//                     past=true;
//                 }
//                 else{
//                     if(past==true){
//                         return false;
//                     }
//                     qu.push(node->left);
//                     qu.push(node->right);
//                 }
//             }
//         }
//         return true;
//       }
// };
