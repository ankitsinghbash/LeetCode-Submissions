class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            char ch = s.at(i);
            if(ch!='*'){
                st.push(ch);
            }
            else if(st.size()!=0 && ch=='*'){
                st.pop();
            }
        }

        string ans;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
