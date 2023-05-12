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
    void inorder(TreeNode *root,vector<int> &store){
       if(root==NULL) return;

       inorder(root->left,store);
       store.push_back(root->val);
       inorder(root->right,store);
    }

 
    TreeNode *BST(int low,int high,vector<int> &arr){
       if(low>high) return nullptr;
     
       int mid = low+(high-low)/2;
       TreeNode *root = new TreeNode(arr[mid]);

       root->left = BST(low,mid-1,arr);
       root->right = BST(mid+1,high,arr);

       return root;
    }



    TreeNode* balanceBST(TreeNode* root) {
        vector<int> store;
        inorder(root,store);
        return BST(0,store.size()-1,store);
      
    }
};
