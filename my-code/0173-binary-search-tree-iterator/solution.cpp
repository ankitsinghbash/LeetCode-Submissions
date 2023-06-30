class BSTIterator {
public:
    stack<TreeNode*> st;
    void solve(TreeNode *root){
        while(root!=NULL){
            st.push(root);
            root=root->left;
        }
    }
   

    BSTIterator(TreeNode* root) {
        solve(root);
    }
    
    int next() {
        TreeNode *node = st.top();
        st.pop();
        solve(node->right);
        return node->val;
    }
    
    bool hasNext() {
        int x = st.size();
        if(x!=0) return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
