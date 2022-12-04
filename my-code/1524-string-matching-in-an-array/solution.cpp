
class Solution {
public:

   bool isSubstring(string s1, string s2)
   {
    // using find method to check if s1 is
    // a substring of s2
    if (s2.find(s1) != string::npos)
        return true;
    return false;
  }



    vector<string> stringMatching(vector<string>& words) {
      set<string> st;
      for(int i=0;i<words.size();i++)
      {
          string wrd1 = words[i];
          for(int j=0;j<words.size();j++)
          {
              if(i!=j)
              {
                  if(wrd1.size()<words[j].size())
                  {
                      bool b =  isSubstring(wrd1,words[j]);
                      if(b==true)
                      {
                          st.insert(wrd1);
                      }
                  }
              }
          }
      }  
      vector<string> ans(st.begin(),st.end());
      return ans;
      


    }
};
