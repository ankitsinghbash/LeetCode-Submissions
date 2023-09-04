class Solution {
public:
 bool vowel(char ch){
      return ch=='a' || ch=='e' || ch=='i'  || ch=='o' || ch=='u' || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U';
   }


   void solve(int start,int last,string &s){
     if(start>=last){
         return;
     }


      if(vowel(s[start]) && vowel(s[last])){
          swap(s[start],s[last]);
          start++;
          last--;
      }

      else if(vowel(s[start])){
          last--;
      }
      else{
          start++;
      }
     
      solve(start,last,s);
   }


    string reverseVowels(string s) {
        //by recursion:
        int n = s.size();
        solve(0,n-1,s);
        return s;
    }
};
