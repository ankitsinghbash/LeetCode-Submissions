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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(root==NULL){
           return ans;
        }

        //simple the bfs and get the maximum value at each level add to vector ans
        
        queue<TreeNode*> qu;
        qu.push(root);
        while(!qu.empty()){
            int size = qu.size();
            int maxx = INT_MIN;
            while(size--){
                TreeNode *node = qu.front();
                qu.pop();
                maxx=max(maxx,node->val);
                if(node->left!=NULL){
                    qu.push(node->left);
                }
                if(node->right!=NULL){
                    qu.push(node->right);
                }

            }
            ans.push_back(maxx);
        }
        return ans;
    }
};
