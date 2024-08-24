class Solution {
public:
    vector<string> store;
    void solve(TreeNode *root,string str){
        if(root==NULL) return;
        
        
       
        
        if(root->left==NULL && root->right==NULL){
              str+=to_string(root->val);
              store.push_back(str);
              return;
        }
        
        
         str+=to_string(root->val)+"->";
        solve(root->left,str);
        solve(root->right,str);
        
        str.pop_back();
        
        
        
        
        
    }
    
    
    
    vector<string> binaryTreePaths(TreeNode* root) {
        string str;
        solve(root,str);
        return store;
    }
};
