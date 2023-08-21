class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        //now optimim version:
        int n = s.size();
        for(int i=0;i<s.size()/2;i++){
               int len = i+1;
               if(n%len==0){
                   int time = n/len;
                   string str = s.substr(0,i+1);
                   string check="";
                   while(time--){
                       check+=str;
                   }
                   if(check==s){
                       return true;
                   }
               }
        }
        return false;
    }
};
