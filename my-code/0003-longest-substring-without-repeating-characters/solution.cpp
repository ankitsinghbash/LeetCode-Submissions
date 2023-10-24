class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       unordered_set<char> st;
       int right=0;
       int left=0;
       int maxx=0;
       while(right<s.size()){
           char ch = s.at(right);
           if(st.find(ch)==st.end()){
               st.insert(ch);
               right++;
               maxx = max(maxx,right-left);
           }
           else{
               char ch = s.at(left);
               st.erase(ch);
               left++;
           }
 
   



       }
       return maxx;
    }
};
