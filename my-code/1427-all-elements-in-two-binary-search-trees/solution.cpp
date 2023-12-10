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
    vector<int> delta1;
    vector<int> delta2;
    void preorder(TreeNode *root,bool flag){
        if(root==NULL) return;
  
      
        preorder(root->left,flag);
        if(flag==true){
            delta1.push_back(root->val);
        }
        else{
            delta2.push_back(root->val);
        }
        preorder(root->right,flag);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        preorder(root1,true);
        preorder(root2,false);
        int i=0;
        int j=0;
        vector<int> store;
        while(i<delta1.size() && j<delta2.size()){
            if(delta1[i]<delta2[j]){
                store.push_back(delta1[i]);
                i++;
            }
            else if(delta1[i]>delta2[j]){
                store.push_back(delta2[j]);
                j++;
            }
            else{
                store.push_back(delta1[i]);
                store.push_back(delta2[j]);
                i++;
                j++;
            }

        }
        while(i<delta1.size()){
            store.push_back(delta1[i]);
            i++;
        }
        while(j<delta2.size()){
            store.push_back(delta2[j]);
            j++;
        }
        return store;
    }
};
