
class Solution {
public:
   unordered_map<int,vector<int>> adj;
   void graph(TreeNode *root){

      queue<TreeNode*> qu;
      qu.push(root);
      while(!qu.empty()){
          int size = qu.size();
          while(size--){
              TreeNode *node = qu.front();
              qu.pop();
              if(node->left!=NULL){
                  qu.push(node->left);
                  adj[node->val].push_back(node->left->val);
              }
              if(node->right!=NULL){
                  qu.push(node->right);
                  adj[node->val].push_back(node->right->val);
              }
          }
      }

   }

    void solve(TreeNode *&root,vector<int> &store){
           if(root==NULL) return;

           store.push_back(root->val);
           solve(root->left,store);
           solve(root->right,store);
    }


    int dfs(int u,int parent_node){
          // if (adj[u].empty()) return 0; //not necessarry because you travel in unordered_map:

      
        int maxx = 0;
        for(auto &v : adj[u]){
            if(v==u) continue;
            int val = abs(parent_node-v);
            maxx = max(maxx,val);
            maxx = max(dfs(v,parent_node),maxx);
            
        }         
       
       return maxx;
          

    }

    int maxAncestorDiff(TreeNode* root) {
        //i required to solve with dfs:
        vector<int> store;
        solve(root,store);
        graph(root);
        int maxx = 0;
        for(int i=0;i<store.size();i++){
            int val = store[i];
            int parent_node = val;
            //unordered_set<int> visited;
            int alpha = dfs(val,parent_node);
            maxx = max(maxx,alpha);
        }
        return maxx;
    }
};
