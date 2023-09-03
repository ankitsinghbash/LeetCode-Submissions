class Solution {
public:
   bool vowel(char &ch){
      return ch=='a' || ch=='e' || ch=='i'  || ch=='o' || ch=='u' || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U';
   }


    string reverseVowels(string s) {
        int low=0;
        int high = s.size()-1;
        while(low<=high){
            char last = s[high];
            char start = s[low];
            if(vowel(last)==true && vowel(start)){
                swap(s[high],s[low]);
                 low++;
                 high--;
            }
            else if(vowel(last)==true){
                low++;
            }
            else{
                high--;
            }
        }
        return s;
    }
};
