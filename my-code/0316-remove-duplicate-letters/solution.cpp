class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> st;
        vector<int> last_occur(26,0);
        for(int i=0;i<s.size();i++){
          last_occur[s[i]-'a']=i;
        }

        vector<bool> visited(26,false);
        for(int i=0;i<s.size();i++){
          char ch = s[i];
          if(visited[ch-'a']==true){
            continue;
          }
          while(st.size()>0 && st.top()>ch && i<last_occur[st.top()-'a']){
            visited[st.top()-'a']=false;
            st.pop();
          }
          st.push(ch);
          visited[ch-'a']=true;
        }

        string ans="";
        while(!st.empty()){
          ans+=st.top();
          st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
};
