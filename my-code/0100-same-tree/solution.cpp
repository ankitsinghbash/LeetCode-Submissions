class Solution {
public:
    bool solve(TreeNode *p, TreeNode *q){
        if(p==NULL || q==NULL){
            return p==q;
        }

        if(p->val!=q->val){
            return false;
        }

        bool flag1 = solve(p->left,q->left);
        bool flag2 = solve(p->right,q->right);


        return flag1&&flag2;

    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return solve(p,q);
    }
};
