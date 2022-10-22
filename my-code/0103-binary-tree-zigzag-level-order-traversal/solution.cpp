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
 /*
class Solution {
public:
    
    void zigzag(int level,TreeNode *root,vector<vector<int>> &answer ){
       stack<TreeNode*> parent,baby; 
       vector<int> ans;
       parent.push(root);
       while(!parent.empty()){
           TreeNode *temp = parent.top();
           parent.pop();
           if(temp){
           ans.push_back(temp->val);
           }
           if(level%2==1)
           {
               if(!temp->left){
               baby.push(temp->left);
               }
               if(!temp->right){
               baby.push(temp->right);
               }
           }
           else{
               if(!temp->right){
               baby.push(temp->right);
               }
               if(!temp->left){
               baby.push(temp->left);
               }
           }
           
           if(parent.size()==0) {
                swap(parent,baby);
                answer.push_back(ans);
                ans.clear();
                level++;
                
            }
       }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> answer;
        zigzag(1,root,answer);
        return answer;
    }
};
*/
class Solution { 
    public:
     vector<vector<int>> zigzagLevelOrder(TreeNode* root) { vector<vector<int>> zigZagLevels;
      if(root==NULL)
       return zigZagLevels;
        vector<int> level; 
        stack<TreeNode*> LtoR; 
         
         stack<TreeNode*> RtoL; 
          
           LtoR.push(root); 
           int lvl = 1;
            //level Number
             while(!LtoR.empty() || !RtoL.empty()){ 
                 if(lvl%2 != 0){ 
                     while(!LtoR.empty())
                     { 
                 if(LtoR.top()->left != NULL) 
                     RtoL.push(LtoR.top()->left);
                 if(LtoR.top()->right !=NULL)
                  RtoL.push(LtoR.top()->right);
                   level.push_back(LtoR.top()->val);
                    LtoR.pop(); 
                    }
                     zigZagLevels.push_back(level);
                      level.clear(); 
                      }
                       else
                        { 
                      while(!RtoL.empty()){
                         if(RtoL.top()->right != NULL)
                          LtoR.push(RtoL.top()->right);
                  if(RtoL.top()->left != NULL)
                   LtoR.push(RtoL.top()->left); 
                   level.push_back(RtoL.top()->val);
                    RtoL.pop(); 
                    } 
                    zigZagLevels.push_back(level);
                     level.clear(); 
                     }
                      ++lvl; 
                     } return zigZagLevels;
                      }
                  };

