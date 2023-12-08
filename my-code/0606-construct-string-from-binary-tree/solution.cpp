
class Solution {
public:
    std::string tree2str(TreeNode* root) {
        // Step 1: Base case - if the root is null, return an empty string
        if (root == nullptr) {
            return "";
        }

        // Step 2: Start with the value of the current node as the result string
        std::string result = std::to_string(root->val);

        // Step 3: Recursively process the left and right subtrees
        std::string leftSubtree = tree2str(root->left);
        std::string rightSubtree = tree2str(root->right);

        // Step 4: Check conditions to determine the final result
        if (leftSubtree.empty() && rightSubtree.empty()) {
            // Both left and right subtrees are empty, return the current result
            return result;
        }
        if (leftSubtree.empty()) {
            // Left subtree is empty, include empty parentheses for it and the right subtree
            return result + "()" + "(" + rightSubtree + ")";
        }
        if (rightSubtree.empty()) {
           
            return result + "(" + leftSubtree + ")";
        }
        return result + "(" + leftSubtree + ")" + "(" + rightSubtree + ")";
    }
};
