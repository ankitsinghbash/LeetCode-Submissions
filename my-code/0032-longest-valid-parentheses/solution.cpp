class Solution {
public:
    int longestValidParentheses(string s) {
       stack<int> st;
       st.push(-1);
       int maxx=0;
       for(int i=0;i<s.size();++i){
            if(s[i]=='('){
                st.push(i);
            }
            else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }
                else{
                    maxx=max(maxx,i-st.top());
                }
            }
       }
       return maxx;
    }
   
};
