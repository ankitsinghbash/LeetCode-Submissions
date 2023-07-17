class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL){
            return {};
        }

       vector<vector<int>> store;
       queue<TreeNode*> qu;
       qu.push(root);
       while(!qu.empty()){
           int size = qu.size();
           vector<int> sm;
           while(size--){
               TreeNode *node = qu.front();
               qu.pop();
               sm.push_back(node->val);
               if(node->left!=NULL){
                   qu.push(node->left);
               }
               if(node->right!=NULL){
                   qu.push(node->right);
               }               
           }
           store.push_back(sm);
           sm.clear();
       }
       return store;
    }
};
