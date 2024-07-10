class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> st;
        int ans=0;
        for(string &str : logs){
            string strs = str;
            if(strs=="./"){
                continue;
            }
            else if(!st.empty() && strs=="../"){
                     st.pop();
            }
            else if(strs!="./" && strs!="../"){
                  st.push(strs);
              }

        }

       
       while(!st.empty()){
        ans++;
        st.pop();
       }
       return ans;

    }
};
