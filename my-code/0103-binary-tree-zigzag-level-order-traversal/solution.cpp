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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL) return {};

        queue<TreeNode*> qu;
        qu.push(root);
        int level=0;
        vector<vector<int>> real;
        while(!qu.empty()){
            int size = qu.size();
            vector<int> ans;
            while(size--){
                TreeNode *node = qu.front();
                qu.pop();
                ans.push_back(node->val);
                if(node->left!=NULL){
                    qu.push(node->left);
                }
                if(node->right!=NULL){
                    qu.push(node->right);
                }
            }
            if(level%2!=0){
                reverse(ans.begin(),ans.end());
            }
            real.push_back(ans);
            level++;
        }
        return real;
    }
    
};


// class Solution {
// public:
//     vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
//         vector<vector<int>> real;
//         if(root==NULL)
//         return real;

//         queue<TreeNode*> q;
//         q.push(root);
//         int level=0;
//         while(!q.empty())
//         {
            
//             int size=q.size();
//             vector<int> ans;
//             while(size--)
//             {
//                 TreeNode* node=q.front();
//                 q.pop();
//                 ans.push_back(node->val);
//                 if(node->left!=NULL)
//                 q.push(node->left);
//                 if(node->right!=NULL)
//                 q.push(node->right);
//                 //not right condtion hare if even or odd that given error in case: [1,2,3,4,null,null,5]
//             }
//             if(level%2!=0)
//                 reverse(ans.begin(),ans.end());
//             real.push_back(ans);
//             level++;
            
//         }
//         return real;
//     }
// };
