class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> last_occur(26,0);
        for(int i=0;i<s.size();i++){
            char ch = s.at(i);
            last_occur[ch-'a']=i;
        }

        vector<bool> visited(26,false);
        stack<char> st;

        for(int i=0;i<s.size();i++){
            char ch = s.at(i);
            if(visited[ch-'a']==true){
                    continue;
            }
   
           //This is the case of unvisited:
           while(st.size()!=0 && st.top()>ch && i<last_occur[st.top()-'a']){  //last_occur me st.top:
               visited[st.top()-'a']=false;
               st.pop();
           }
           st.push(ch);
           visited[ch-'a']=true;
        }

        string ans;
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
        return ans;

    }
};
