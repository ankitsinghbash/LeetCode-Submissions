class Solution {
public:
   void solve(TreeNode *root,int &sum,string str){
      if(root==NULL) return;
   
      str+=to_string(root->val);
      if(root->left==NULL && root->right==NULL){
          sum+=stoi(str);
          str.pop_back();
          return;
      } 
       solve(root->left,sum,str);
       solve(root->right,sum,str);
   }



    int sumNumbers(TreeNode* root) {
        int sum=0;
        solve(root,sum,"");
        return sum;
    }
};
