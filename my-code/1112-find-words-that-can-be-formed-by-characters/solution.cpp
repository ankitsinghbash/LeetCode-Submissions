class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> alpha(26);
        for(char ch : chars){
            alpha[ch-'a']++;
        }

   
      int total=0;
      for(string str : words){
          vector<int> alpha2(alpha.begin(),alpha.end());
          bool flag=true;
          for(char ch : str){
                alpha2[ch-'a']--;
                if(alpha2[ch-'a']<0){
                    flag=false;
                    break;
                }
          }
          if(flag==true){
             total+=str.size();
          }
      }
      return total;

    }
};
