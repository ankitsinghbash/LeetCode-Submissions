class Solution {
public:
    int addMinimum(string word) {
        stack<char> st;
        for(int i=0;i<word.size();i++)
        {
            st.push(word[i]);
        }
        int count=0;
        while(!st.empty())
        {
            if(st.size()!=0 && st.top()=='c'){
            st.pop();
            }
            else{
            count++;
            }
            if(st.size()!=0 && st.top()=='b'){
                      st.pop();
            } 
            else{
            count++;
            }
            if(st.size()!=0 && st.top()=='a'){
            st.pop();
            }
            else{
            count++;
            }
            
        }
        return count;
    }
};
