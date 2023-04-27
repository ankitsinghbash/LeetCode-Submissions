class Solution {
public:
    int addMinimum(string word) {
        stack<char> st;
        for(char ch : word){
            st.push(ch);
        }
        
        int cnt=0;
        while(!st.empty()){
            if(st.size()!=0 && st.top()=='c'){
                st.pop();
            }
            else{
                cnt++;
            }
            if(st.size()!=0 && st.top()=='b'){
                 st.pop();    
            }
            else{
                cnt++;
            }
            if(st.size()!=0 && st.top()=='a'){
                st.pop();
            }
            else{
                cnt++;
            }
            
        }
        return cnt;
        
    }
};
