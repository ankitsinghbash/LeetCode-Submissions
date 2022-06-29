class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++)
        {
           char x=s[i];
           if(x=='('||x=='{'||x=='[')
                st.push(s[i]);
           else if(st.size()!=0&&x==')'&&st.top()=='(')
           st.pop();
           else if(st.size()!=0&&x=='}'&&st.top()=='{')
           st.pop();
           else if(st.size()!=0&&x==']'&&st.top()=='[')
           st.pop();
           else
               return false;
        }
        return st.empty();
    }
};
