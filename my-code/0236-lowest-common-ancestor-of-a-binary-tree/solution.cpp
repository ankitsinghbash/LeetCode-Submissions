class Solution {
public:
    bool solve(TreeNode *root,TreeNode *p,vector<TreeNode*> &path1){
        if(root==NULL){
            return false;
        }

         if(root->val==p->val){
             path1.push_back(root);
             return true;
         }

        bool left = solve(root->left,p,path1);
        if(left==true){
            path1.push_back(root);
            return true;
        }

        bool right = solve(root->right,p,path1);
        if(right==true){
            path1.push_back(root);
            return true;
        }

        return false;

    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //lowest common ancestor using vector<listnode*> method:

       //root to path in a tree:
        vector<TreeNode*> path1;
        vector<TreeNode*> path2;
        solve(root,p,path1);
        solve(root,q,path2);
         
        int len1 = path1.size();
        int len2 = path2.size();
       

        int j1 = len1-1;
        int j2  = len2 -1;
        while(j1>=0 && j2>=0 && path1[j1]==path2[j2]){
            j1--;
            j2--;
        }
        return path1[j1+1];


        

    }
};
