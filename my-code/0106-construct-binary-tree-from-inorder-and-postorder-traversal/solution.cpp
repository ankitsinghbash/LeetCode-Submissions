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
 
   TreeNode *solve(vector<int> &inorder,vector<int> &postorder,int inStart,int inEnd,int pStart,int pEnd){

    if(pStart>pEnd || inStart>inEnd){  //base case : Write only one is also satisfied the base case:  
        return NULL;
    }
    
     TreeNode *root = new TreeNode(postorder[pEnd]);

    int i = inStart; 
    for(;i<=inEnd;i++){     //find the root postion in the inorder:
        if(inorder[i]==root->val){
            break;
        }
    }
 
    int leftsize = i-inStart;   //inorder me left size:
    int rightsize = inEnd - i;    //inorder me right size:
   root->left = solve(inorder,postorder,inStart,i-1,pStart,pStart+leftsize-1);//we pass new inorder and new postorder at left side wala:
     root->right = solve(inorder,postorder,i+1,inEnd,pEnd-rightsize,pEnd-1);//we pass new inorder and new postorder at right side wala:
     return root;
   }



    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int inStart = 0;
        int inEnd = inorder.size()-1;
        int pStart = 0;
        int pEnd = postorder.size()-1;
        return solve(inorder,postorder,inStart,inEnd,pStart,pEnd);
    }
};
