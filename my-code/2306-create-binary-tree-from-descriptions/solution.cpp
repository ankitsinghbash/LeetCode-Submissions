
class Solution {
public:
    TreeNode *solve(int parent_node,unordered_map<int,vector<pair<int,int>>> &adj){
          if(adj.find(parent_node)==adj.end()){
            TreeNode *new_node = new TreeNode(parent_node);
            return new_node;
          }


          TreeNode *node=new TreeNode(parent_node);
          for(auto &v : adj[parent_node]){
              int child = v.first;
              int pos = v.second;
              if(pos==1){
                  node->left = solve(child,adj);
              }
              else{
                  node->right = solve(child,adj);
              }

          }


          return node;


         


    }


    TreeNode* createBinaryTree(vector<vector<int>>& des) {
        //for child:
        //isleft==0 then present in rightL:
        //isleft==1 then present in left:
        unordered_set<int> st;   //set take all the child value:
        int n = des.size();
        for(int i=0;i<n;i++){
            int parent = des[i][0];
            int child = des[i][1];
            int pos = des[i][2];

            st.insert(child);
        }

        int parent_node;
        for(int i=0;i<n;i++){
            int parent = des[i][0];
            if(st.find(parent)==st.end()){   //the vlaue not present in my set so that was my parent:
                parent_node = parent;
            }
        }


        unordered_map<int,vector<pair<int,int>>> adj;
        
          for(int i=0;i<n;i++){
            int parent = des[i][0];
            int child = des[i][1];
            int pos = des[i][2];
            adj[parent].push_back({child,pos});
        }


        return solve(parent_node,adj);
        






    }
};
