class Solution {
public:
    vector<TreeNode*> ans;
    TreeNode *solve(TreeNode *&root,unordered_set<int> &st){
          if(root==NULL)  return NULL;




          solve(root->left,st);
          solve(root->right,st);

          if(st.find(root->val)!=st.end()){
                 if(root->left==NULL && root->right==NULL){
                    //case of child node:
                    TreeNode *node = root;
                    root = NULL;
                    return node;       
                 }
                 else if(root->left==NULL){
                     ans.push_back(root->right);
                     TreeNode *node = root;
                     root = NULL;
                     return node;
                 }
                 else if(root->right==NULL){
                    ans.push_back(root->left);
                    TreeNode *node = root;
                    root=NULL;
                    return node;
                 }
                 else if(root->left!=NULL && root->right!=NULL){
                    //both left and right present || root never be a children node:
                    ans.push_back(root->left);
                    ans.push_back(root->right);
                    TreeNode *node = root;
                    root = NULL;
                    return node;
                 }

          }
      
          return root;
          
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> st;
        for(int i=0;i<to_delete.size();i++){
            st.insert(to_delete[i]);
        }
       
       TreeNode *node =  solve(root,st);
         if(st.find(node->val)==st.end()){
            //root is not present in set means no need to delete it:
            ans.push_back(root);
        }
        return ans;
    }
};
