class Solution {
public:
    bool solve(TreeNode *p,TreeNode *q){
        if(p==NULL || q==NULL){
            return p==q;  //structure 
        }
        
        
        if(p->val!=q->val){   //node value same or not:
            return false;
        }
        
        
        
        bool left = solve(p->left,q->left);
        bool right = solve(p->right,q->right);
        
        
        return left&&right;
        
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return solve(p,q);
    }
};
