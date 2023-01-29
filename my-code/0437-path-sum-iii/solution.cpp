class Solution {
public:
    //approach 1;
   vector<long long> solve_postorder(TreeNode *root,int target,int &counter){


       if(root==NULL){
           vector<long long> v;
           return v;   //empty vector;
       }


       vector<long long> left_vector = solve_postorder(root->left,target,counter);
       vector<long long > right_vector = solve_postorder(root->right,target,counter);
 
       vector<long long> curr_vector;
       for(auto &Left : left_vector){
           curr_vector.push_back(Left+root->val);
       }

       for(auto &Right : right_vector){
           curr_vector.push_back(Right+root->val);
       }
       curr_vector.push_back(root->val);

       //now find the target in current;
       for(auto &x : curr_vector){
           if(x==target){
               counter++;
           }
       }

       return curr_vector;

   }
 
 
    int pathSum(TreeNode* root, int targetSum) {
        int counter=0;
        if(root==NULL) return 0;

        solve_postorder(root,targetSum,counter);
        return counter;
    }
};

//approch 2 give tle understand how recursion work;
// class Solution {
// public:

//     void solve(TreeNode *root,int target,vector<int> &path,int &counter){

//       if(root==NULL){
//           return;
//       }
   
//       path.push_back(root->val);
//       solve(root->left,target,path,counter);
//       solve(root->right,target,path,counter);

//       int sum=0;
//       for(int i=path.size()-1;i>=0;i--){
//           sum+=path[i];
//           cout<<path[i]<<" ";
//           if(sum==target){
//               counter++;
//           }
//       }
//       cout<<endl;
//       path.pop_back();

    
//     }

//     int pathSum(TreeNode* root, int targetSum) {
//         vector<int> path;
//         int counter=0;
//         solve(root,targetSum,path,counter);
//         return counter;
//     }
// };
