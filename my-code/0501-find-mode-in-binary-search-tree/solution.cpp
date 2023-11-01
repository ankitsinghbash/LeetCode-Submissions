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
    unordered_map<int,int> mp;
    void solve(TreeNode *root){
       
        if(root==NULL){
            return;
        }
   

        mp[root->val]++;
        solve(root->left);
        solve(root->right);

    }

    vector<int> findMode(TreeNode* root) {
        //brute force:
        solve(root);

        int maxx=0;
        for(auto it = mp.begin();it!=mp.end();it++){
            if(it->second>maxx){
                maxx=it->second;
            }
        }
        vector<int> ans;
        for(auto it = mp.begin();it!=mp.end();it++){
            if(it->second==maxx){
                ans.push_back(it->first);
            }
        }
        return ans;
    }
};
