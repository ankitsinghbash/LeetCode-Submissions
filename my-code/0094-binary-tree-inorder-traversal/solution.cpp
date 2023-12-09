
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        //iterative way:
        //what is inorder:left,root,right:
        vector<int> store;
        stack<TreeNode*> st;
        TreeNode *curr = root;
        while(curr!=NULL || !st.empty()){
                while(curr!=NULL){
                    st.push(curr);
                    curr=curr->left;
                }

                TreeNode *node = st.top();
                store.push_back(node->val);
                st.pop();
                curr = node->right;
        }
        return store;
    }
};
