class Solution {
public:
   //using graph and bfs:
//    unordered_map<int,vector<int>> mp;    //dfs approach to add value in the mp;
//      int solve(TreeNode *root){    
//       if(root==NULL) return -1;

//       int left = solve(root->left);
//       int right = solve(root->right);

//       mp[left].push_back(root->val);
//       mp[root->val].push_back(left);
//       mp[right].push_back(root->val);
//       mp[root->val].push_back(right);
    
//       return root->val;

//    }
     

     //bfs approach to add value int the node:
     unordered_map<int,vector<int>> mp;
     void solve(TreeNode *root){
         queue<TreeNode*> qu;
         qu.push(root);
         while(!qu.empty()){
             int size = qu.size();
             while(size--){
                 TreeNode *node = qu.front();
                 qu.pop();
                 if(node->left!=NULL){
                     qu.push(node->left);
                     mp[node->left->val].push_back(node->val);
                     mp[node->val].push_back(node->left->val);
                 }
                 if(node->right!=NULL){
                      qu.push(node->right);
                      mp[node->right->val].push_back(node->val);
                      mp[node->val].push_back(node->right->val);
                 }
             }
         }
     }



      int cnt=-1;
   void bfs(int start,unordered_map<int,vector<int>> &mp,unordered_set<int> &st){

        
           queue<int> qu;
           qu.push(start);
           st.insert(start);
           while(!qu.empty()){
               int size = qu.size();
               cnt++;
               while(size--){
                   int v = qu.front();
                   qu.pop();
                   for(auto u : mp[v]){
                       if( st.find(u)==st.end()){
                           qu.push(u);
                           st.insert(u);
                       }
                   }
               }
           }

   }

    int amountOfTime(TreeNode* root, int start) {
        solve(root);
        unordered_set<int> st;
        bfs(start,mp,st);
        return cnt;
    }
};
