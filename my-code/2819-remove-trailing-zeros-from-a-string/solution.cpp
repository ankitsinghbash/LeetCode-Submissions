class Solution {
public:
    string removeTrailingZeros(string num) {
      string str = num;
      reverse(str.begin(),str.end());
      string s;
      bool flag=true;
      for(char ch : str){
          if(ch=='0' && flag==true){
              continue;
          }
          else{
              flag=false;
              s+=ch;
          }
      }
      reverse(s.begin(),s.end());
      return s;
    }
};
