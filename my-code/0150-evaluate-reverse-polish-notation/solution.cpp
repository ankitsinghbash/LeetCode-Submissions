class Solution {
public:
    int evalRPN(vector<string>& vec) {
        stack<string> st;
        for(int i=0;i<vec.size();i++){
            string ch  = vec[i];
            if(ch=="+" || ch=="*" || ch=="-" || ch=="/"){
                   string B = st.top();
                   st.pop();
                   string A = st.top();
                   st.pop();
                   int val_b = stoi(B);
                   int val_a = stoi(A);
                   int result;
                   if(ch=="+"){
                       result = val_a+val_b;
                   }
                   else if(ch=="-"){
                       result = val_a-val_b;
                   }
                   else if(ch=="*"){
                       result = val_a*val_b;
                   }
                   else{
                       result = val_a/val_b;
                   }
                   string new_str = to_string(result);
                   st.push(new_str);
            }
            else{
                st.push(ch);
            }
        }

        string s = st.top();
        int ans = stoi(s);
        return ans;
    }
};
