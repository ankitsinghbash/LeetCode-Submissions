class Solution {
public:

   void make_parent(TreeNode *root,unordered_map<TreeNode*,TreeNode*> &mp){
        queue<TreeNode*> qu;
        qu.push(root);
        while(!qu.empty()){
            TreeNode *current = qu.front();
            qu.pop();
            if(current->left!=NULL){
                qu.push(current->left);
                mp[current->left]=current;
            }
            if(current->right!=NULL){
                qu.push(current->right);
                mp[current->right]=current;
            }
        }
   }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> mp;
        make_parent(root,mp);   //make parent use for go to above direction:

        //make a visisted array so that 2--> to 5 and 7-->5 repeating value not allow:
        unordered_map<TreeNode*,bool> visited;
        queue<TreeNode*> qu;
        qu.push(target);
        visited[target]=true;
        int current_level=0;
        while(!qu.empty()){
            int size = qu.size();
            
              if(current_level==k){       //[0,1,null,null,2,null,3,null,4] when node=3 and traget=0:
                break;
            }
             current_level++;
            while(size--){
                TreeNode *node = qu.front();
                qu.pop();
                if(node->left!=NULL && visited[node->left]==false){
                    qu.push(node->left);
                    visited[node->left]=true;
                }
                if(node->right!=NULL && visited[node->right]==false){
                    qu.push(node->right);
                    visited[node->right]=true;
                }
                if(mp[node] && visited[mp[node]]==false){
                    qu.push(mp[node]);
                    visited[mp[node]]=true;
                }
            }

            //if we write the same condition here of break curr_level==k then we now actually we required the
            //qu rest value so for here qu got some value that why the above test case is not submited if we //use current_level==k {break} Here:  

        }

        vector<int> ans;
        while(!qu.empty()){
            TreeNode *node = qu.front();
            qu.pop();
            ans.push_back(node->val);
        }
        return ans;
    }
};
