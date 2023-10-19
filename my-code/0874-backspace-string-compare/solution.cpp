class Solution {
public:
    bool backspaceCompare(string ss, string tt) {
        //stack:
        stack<char> st;
        for(int i=0;i<ss.size();i++){
            char ch = ss.at(i);
            if(ch!='#'){
                st.push(ch);
            }
            else{
                if(st.size()>0){
                  st.pop();
                }
            }
        }
  
        stack<char> st1;
        for(int i=0;i<tt.size();i++){
            char ch = tt.at(i);
            if(ch!='#'){
                st1.push(ch);
            }
            else{
                if(st1.size()>0){
                    st1.pop();
                }
            }
        }


        string s;
        while(!st.empty()){
                s=st.top()+s;
                st.pop();
        }

        string t;
        while(!st1.empty()){
            t=st1.top()+t;
            st1.pop();
        }
        return s==t;
    }
};
