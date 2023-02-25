class Solution {
public:
    bool backspaceCompare(string s, string t) {
       string str1="";
       int low=0;
       int  n  = s.size();
       while(low<n){
           char ch = s.at(low);
           if(ch == '#'){
              if(str1.size()!=0){
                  str1.pop_back();
              }
           }
           else{
               str1+=ch;
           }
           low++;
       }

       int start=0;
       string str2="";
       int  m  = t.size();
       while(start<m){
           char ch = t.at(start);
           if(ch == '#'){
              if(str2.size()!=0){
                  str2.pop_back();
              }
           }
           else{
               str2+=ch;
           }
           start++;
       }
       cout<<str1<<endl;
       cout<<str2<<endl;
       if(str1==str2){
           return true;
       }
       else{
           return false;
       }

    }
};
