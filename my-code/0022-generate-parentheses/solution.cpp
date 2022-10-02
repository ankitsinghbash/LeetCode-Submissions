class Solution {
public:
   vector<string> ans;
    void helper(int n,int r,string path)
    {
      //base when n and r both become 0: return ans:
      if(n==0&&r==0)
      {
          ans.push_back(path);
          return;
      }

      if(n>0)
       {
           helper(n-1,r+1,path+'(');
       }
      
      if(r>0)
      {
          helper(n,r-1,path+')');
      }


    }

    vector<string> generateParenthesis(int n) {
        int r=0;
        string path;
        helper(n,r,path);   //find for most simple string->()() n=2 and for n=3->()()() it's visilution is very easy:
        return ans;
    }
};
