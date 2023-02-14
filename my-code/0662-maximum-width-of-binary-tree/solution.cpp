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
        qu.push({root,0});
        int ans=0;
        while(!qu.empty()){

            int size = qu.size();
            int mini =  qu.front().second;
            int curr,last;
             for(int i=0;i<size;i++){
                pair<TreeNode*,int> P = qu.front();
                qu.pop();
                TreeNode *node = P.first;
                long long  val = P.second-mini;
                if(i==0){
                    curr = val;
                }
                if(i==size-1){
                    last = val;
                }
                if(node->left!=NULL){
                    qu.push({node->left,2*val+1});
                }
                if(node->right!=NULL){
                    qu.push({node->right,2*val+2});
                }
            }
            ans=max(ans,last-curr+1);
        }
        return ans;
    }
};
