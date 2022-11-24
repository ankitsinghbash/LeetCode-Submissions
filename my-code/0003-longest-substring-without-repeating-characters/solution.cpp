class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         
         int left=0;
         int right=0;
         set<char> st;
         int maxx=0;
         while(right<s.size())
         {
             char ch = s.at(right);
             if(st.find(ch)==st.end())
             {
                 st.insert(ch);
                 maxx=max(maxx,right-left+1);
                 
                 right++;
             }
             else
             {
                 char ch = s.at(left);
                 st.erase(ch);
                 left++;
             }

         }
        return maxx;

    }
};
