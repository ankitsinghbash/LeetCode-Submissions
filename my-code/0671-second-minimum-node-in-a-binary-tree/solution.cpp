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
   
   void solve(TreeNode *root,vector<int> &ans){
       if(root==NULL) return;

       solve(root->left,ans);
       ans.push_back(root->val);
       solve(root->right,ans);
   }
 

    int findSecondMinimumValue(TreeNode* root) {
        vector<int> ans;
        solve(root,ans);
        set<int> s(ans.begin(),ans.end());
        if(s.size()<=1){
            return -1;
        }
        else{
             auto it = next(s.begin(),1);
            //or
            // auto it=s.begin();
            // advance(it,1);
            return *it;

        }
    }
};

//this is also use to get the nth elment in the set<int> or use advance(it,nth) function:
// auto it=s.begin();
// for(int i=0;i<nth;i++){
//     it++;
// }
// cout<<*it<<endl;

