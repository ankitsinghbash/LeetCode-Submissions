class Solution {
public:
   int cnt = 0;
   void solve(TreeNode *root,int target,vector<int> path){
      if(root==NULL) return;
   
      path.push_back(root->val);
      solve(root->left,target,path);
      solve(root->right,target,path);

      long long sum=0;
      for(int i=path.size()-1;i>=0;i--){
          sum+=path[i];
          if(sum==target){
              cnt++;
          }
      }
      path.pop_back();
   }



    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return 0;

        vector<int> path;
        solve(root,targetSum,path);
        return cnt;
    }
};


// //method 1:
// //MOst easy every sub-tree(left,right) -> pe jaao or target find karo every path me:
// class Solution {
// public:
//     void dfs(TreeNode *root,long long target,int &cnt){
//        if(root==NULL) return;

//        target=target-root->val;
//        if(target==0){
//            cnt++;
//        }
//        dfs(root->left,target,cnt);
//        dfs(root->right,target,cnt);
//     }

//     void solve(TreeNode *root,long long targetSum,int &cnt){
//         if(root==NULL){
//             return;
//         }

//         dfs(root,targetSum,cnt);    
//         solve(root->left,targetSum,cnt);
//         solve(root->right,targetSum,cnt);  

//     }

//     int pathSum(TreeNode* root, int targetSum){
//         if(root==NULL) return 0;

//         int cnt = 0;
//         solve(root,targetSum,cnt);
//         return cnt;
//     }
// };
