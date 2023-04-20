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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        queue<pair<TreeNode*,int>> qu;
        qu.push({root,1});
        int maxx=0;
        while(!qu.empty()){
            int size = qu.size();
            int mini = qu.front().second;   //Each level ki first value:
            int first,last;
            for(int i=0;i<size;i++){
                TreeNode *node = qu.front().first;
                long long val = qu.front().second-mini;  //here is use long long:
                qu.pop();
                if(i==0){
                    first = val;
                }
                if(i==size-1){
                    last = val;
                }
                if(node->left!=NULL){
                     qu.push({node->left,val*2});
                }
                if(node->right!=NULL){
                    qu.push({node->right,val*2+1});
                }
            }
            maxx = max(maxx,last-first+1);
        }
        return maxx;
    }
};
