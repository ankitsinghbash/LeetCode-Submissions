class Solution {
public:
    string getSmallestString(string s) {
        
           for(int i=1;i<s.size();i++){
               int val1 = s[i-1]-'0';
               int val2 = s[i]-'0';
               if(val1%2==0 && val2%2==0){
                    if(val1>val2){
                        swap(s[i-1],s[i]);
                        break;
                    }
               }
               else if(val1%2!=0 && val2%2!=0){
                     if(val1>val2){
                         swap(s[i-1],s[i]);
                          break;
                     }
               }
           }
        return s;
    }
};
