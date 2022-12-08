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
   vector<int> v1;
   vector<int> v2;
 
    void addleave2(TreeNode *root2){
            
      if(root2==NULL){
          return;
      }

      if(root2->left==NULL&&root2->right==NULL){
          v2.push_back(root2->val);
          cout<<"Data root2 "<<root2->val<<" ";
          return;
      }
          
          addleave2(root2->left);
          addleave2(root2->right);
        
   }



   void addleave1(TreeNode *root1){
            
      if(root1==NULL){
          return;
      }

      if(root1->left==NULL&&root1->right==NULL){
          v1.push_back(root1->val);
          cout<<"data root1 "<<root1->val<<" ";
        //   return;
      }
         
          addleave1(root1->left);
          addleave1(root1->right);
         
   }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        addleave1(root1);
        cout<<endl;
        addleave2(root2);
        
        // if(v1.size()!=v2.size()) return false;

        // for(int i=0,j=0;i<v1.size();i++,j++){
        //     if(v1[i]!=v2[j]) return false;
        // }
        // return true;
        if(v1 == v2) return true;
        return false;
    }
};
