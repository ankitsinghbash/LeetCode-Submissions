class Solution {
public:
    string reverseParentheses(string s) {
            stack<int> st;
            for(int i=0;i<s.size();i++){
                if(s[i]=='('){
                    st.push(i);
                }
                else if(s[i]==')'){
                      int end = i-1;
                      int start = st.top()+1;
                      st.pop();

                      //reverse the mains string:
                      reverse(s.begin()+start,s.begin()+end+1);
                }
            }
            
            string ans;
            for(int i=0;i<s.size();i++){
                if(s[i]!='(' && s[i]!=')'){
                    ans+=s[i];
                }
            }
            return ans;
    }
};
