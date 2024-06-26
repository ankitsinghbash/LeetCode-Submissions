class Solution {
public:

    void inorder(TreeNode *root,vector<int> &store){
          if(root==NULL) return;

          inorder(root->left,store);
          store.push_back(root->val);
          inorder(root->right,store);

    }
   
    TreeNode *solve(vector<int> &store,int low,int high){
             if(low>high) return NULL;  
          
             int mid = low+(high-low)/2;
             TreeNode *new_node = new TreeNode(store[mid]);
             new_node->left = solve(store,low,mid-1);
             new_node->right = solve(store,mid+1,high);
            
             return new_node; 
    }

    TreeNode* balanceBST(TreeNode* root) {
         vector<int> store;
         inorder(root,store);
        
         int low=0;
         int high = store.size()-1;
         return solve(store,low,high);

    }
};
