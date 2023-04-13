class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int first = popped[0];
        int i;
        for(i=0;i<pushed.size();i++){
            st.push(pushed[i]);
            if(pushed[i]==first){
             break;
            }
        }
        int j = i+1;
        cout<<j<<endl;
        int k=0;
        while(j<=pushed.size() && k<popped.size()){
            if(st.size()!=0 && popped[k]==st.top()){
                st.pop();
                k++;
            }
            else{
                if(j<pushed.size()){
                st.push(pushed[j]);
                }
                j++;
            }
        }

        return st.empty();

    }
};
