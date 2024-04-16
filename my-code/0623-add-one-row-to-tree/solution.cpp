
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode *new_node = new TreeNode(val);
            new_node->left = root;
            return new_node;
        }

        queue<TreeNode*> qu;
        qu.push(root);
        int currdepth=1;
        while(currdepth<depth-1){
               int size = qu.size();
               while(size--){
                 TreeNode *node = qu.front();
                 qu.pop();
                 if(node->left!=NULL){
                    qu.push(node->left);
                 }
                 if(node->right!=NULL){
                    qu.push(node->right);
                 }
               }
            currdepth++;
        }

        while(!qu.empty()){
            int size = qu.size();
            while(size--){
                 TreeNode *node = qu.front();
                 qu.pop();
                 TreeNode *lefty = node->left;
                 TreeNode *righty = node->right;

                 TreeNode *new_node_left = new TreeNode(val);
                 TreeNode *new_node_right = new TreeNode(val);

                 node->left = new_node_left;
                 node->right = new_node_right;


                 new_node_left->left = lefty;
                 new_node_right->right = righty;
            }
            return root;
        }
        return root;
    }
};
