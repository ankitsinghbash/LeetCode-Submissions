class Solution {
public:
    string ans="";
    void solve(TreeNode *root,string curr){
        if(root==NULL) return;
        
        if(root->left==NULL && root->right==NULL){
            curr = char('a' + root->val) + curr;
            string new_str = curr;
            //condition:
            if(ans=="" || curr<ans){
                ans = curr;
            }
            curr.pop_back();
            return;
        }
        
        curr = char('a' + root->val) + curr;
        solve(root->left,curr);
        solve(root->right,curr);
        curr.pop_back();
         
    }
    
    string smallestFromLeaf(TreeNode* root) {
        solve(root,"");
        return ans;
    }
};
