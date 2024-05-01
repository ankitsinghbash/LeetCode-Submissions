class Solution {
public:
    string reversePrefix(string word, char ch) {
         int i=0;
         for(;i<word.size();i++){
            if(word[i]==ch){
                break;
            }
         }


         //now reverse from 0 to i:
         if(i==word.size()) return word;
         reverse(word.begin()+0,word.begin()+i+1);
         return word;
    }
};
