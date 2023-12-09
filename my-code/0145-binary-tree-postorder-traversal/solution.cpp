class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
               vector<int> store;
        stack<TreeNode*> st;
        TreeNode *curr = root;
        TreeNode *lastVisited = nullptr;

        while (curr != nullptr || !st.empty()) {
            while (curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }

            TreeNode *node = st.top();

            // Check if we can visit the current node's right subtree
            if (node->right != nullptr && node->right != lastVisited) {
                curr = node->right;
            } else {
                // Visit the current node since it has no right subtree or the right subtree is already visited
                store.push_back(node->val);
                st.pop();
                lastVisited = node;
            }
        }

        return store;
    }
};
