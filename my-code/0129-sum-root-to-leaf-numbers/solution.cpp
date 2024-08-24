class Solution {
public:
    int ans=0;
    void solve(TreeNode *root,string str){
        
         if(root==NULL) return;
        
        
        str+=to_string(root->val);
        if(root->left==NULL && root->right==NULL){
             int value = stoi(str);
              ans+=value;
        }
        
        solve(root->left,str);
        solve(root->right,str);
        str.pop_back();
        
        
    }
    
    int sumNumbers(TreeNode* root) {
            string str;
           solve(root,str);
           return ans;
    }
};
