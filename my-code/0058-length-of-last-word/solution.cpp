class Solution {
public:
    int lengthOfLastWord(string s) {
       int firstgap=0;
       int word = 0;
       for(int i=s.size()-1;i>=0;i--){
            if(s[i]==' '){
                firstgap++;
            }
            if(s[i]!=' '){
                word++;
            }
            if(word!=0 && s[i]==' ' ){
                break;
            }
       }
       return word;
    }
};
