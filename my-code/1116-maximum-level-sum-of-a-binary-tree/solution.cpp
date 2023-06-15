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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> qu;
        qu.push(root);
        int level = 0;
        int x=0;
        int mini = INT_MIN;
        while(!qu.empty()){
            int size = qu.size();
            int sum =0;
            while(size--){
                TreeNode* node = qu.front();
                sum+=node->val;
                qu.pop();
                if(node->left!=NULL){
                    qu.push(node->left);
                }
                if(node->right!=NULL){
                    qu.push(node->right);
                }
            }
            level++;
            if(sum>mini){
                mini = sum;
            x=level;
            }
        }
        return x;
    }
};
