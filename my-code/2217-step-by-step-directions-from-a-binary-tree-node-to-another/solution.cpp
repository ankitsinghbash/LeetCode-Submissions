class Solution {
public:
     vector<pair<int, char>> path1, path2;
    
 
    bool solve(TreeNode* &root, int val, vector<pair<int, char>>& path) {
        if (!root) return false;
        if (root->val == val) return true;
        
        path.push_back({root->val, 'L'});
        if (solve(root->left, val, path)) return true;
        path.pop_back();
        
        path.push_back({root->val, 'R'});
        if (solve(root->right, val, path)) return true;
        path.pop_back();
        
        return false;
    }
    

    


    string getDirections(TreeNode* root, int startValue, int destValue) {
        //I just required root to startvalue,root to destvalue:
    
       
        solve(root,startValue,path1);
        solve(root,destValue,path2);


      
         int i=0;
         int j=0;
         while(i<path1.size() && j<path2.size()){
            if(path1[i]==path2[j]){
                i++;
                j++;
            }
            else{
                break;
            }
         }

        string str;        //path1 for i change to "U";
        //path1 is same:
        for(int k = i;k<path1.size();k++){
            str+="U";
        }

        for(int k = j;k<path2.size();k++){
            str+=path2[k].second;
        }

        return str;       

    }
};
