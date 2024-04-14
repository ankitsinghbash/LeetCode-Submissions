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
    int solve(TreeNode *root){
        if(root->left==NULL && root->right==NULL){
            return 0;
        }
        int sum=0;
        queue<pair<TreeNode*,bool>> qu;
        qu.push({root,false});
        while(!qu.empty()){
            int size = qu.size();
            for(int i=0;i<size;i++){
                pair<TreeNode*,bool> P = qu.front();
                qu.pop();
                TreeNode *node = P.first;
                bool flag = P.second;
                if(node->left!=NULL){
                    qu.push({node->left,true});
                }
                if(node->right!=NULL){
                    qu.push({node->right,false});
                }
                if(flag==true &&  node->left==NULL && node->right==NULL){
                    sum+=node->val;
                }
            }
        }

        return sum;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        //level order wise using bfs:
        return solve(root);
    }
};
