class Solution {
public:
    vector<vector<int>> store;
    void solve(TreeNode *root,int target,vector<int> sm){
       if(root==NULL) return;

       target=target-root->val;
       sm.push_back(root->val);

       if(target==0 && root->left==NULL && root->right==NULL){
           store.push_back(sm);
       }
      
      solve(root->left,target,sm);
      solve(root->right,target,sm);
      sm.pop_back();
    }


    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> sm;
        solve(root,targetSum,sm);
        return store;
    }
};
