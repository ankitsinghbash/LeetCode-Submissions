/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
 
   int mini_swap(vector<int> &small){
       int ans = 0;

       vector<pair<int,int>> p;
       for(int i=0;i<small.size();i++){
           p.push_back({small[i],i});
       }

       sort(p.begin(),p.end());
       for(int i=0;i<small.size();i++){
           if(p[i].second == i){
               continue;
           }

           while(p[i].second!=i){
               ans++;
               swap(p[i],p[p[i].second]);
           }
       }
       return ans;

   }


    int minimumOperations(TreeNode* root) {
        int cnt = 0;
        queue<TreeNode*> qu;
        qu.push(root);
        while(!qu.empty()){
            int size = qu.size();
            vector<int> small;
            while(size--){
                TreeNode *node = qu.front();
                qu.pop();
                small.push_back(node->val);
                if(node->left!=NULL){
                    qu.push(node->left);
                }
                if(node->right!=NULL){
                    qu.push(node->right);
                }
            }
            cnt+=mini_swap(small);  //count the minimum swap->inversion but not (n*log(N)) has in merge_sort in inversion count:
        }
        return cnt;
    }
};
